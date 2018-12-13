#ifndef _MAP_H_
#define _MAP_H_
using namespace std;

template<class key, class info>
struct _pair {
	typedef key _first_type;
	typedef info _second_type;
	key first;
	info second;
	_pair() : first(NULL), second(NULL) {}
	_pair(const key& t_key, const info& t_info) : first(t_key), second(t_info) {}
	_pair(const _pair<key, info>& t_pair) : first(t_pair.first), second(t_pair.second) {}
	~_pair() {
		first = NULL;
		second = NULL;
	}

	_pair<key, info>& _make_pair(const key& t_key, const info& t_info) {
		first = t_key;
		second = t_info;
		return *this;
	}

	_pair<key, info>& operator = (const _pair<key, info>& t_pair) {
		first = t_pair.first;
		second = t_pair.second;
		return *this;
	}
	_pair<key, info>& operator = (_pair<key, info>&& t_pair) {
		first = t_pair.first;
		t_pair.first = nullptr;
		second = t_pair.second;
		t_pair.second = nullptr;
		return *this;
	}

	const _pair<key, info>& operator * () {
		return this;
	}
	const _pair<key, info>* operator -> () {
		return *this;
	}
};

template<class key, class info>
class _map_iterator {
private:
	_pair<key, info>* cur;
public:
	_map_iterator() {}
	_map_iterator(_pair<key, info>* it) : cur(it) {}
	~_map_iterator() {
		cur = nullptr;
	}

	_pair<key, info>* get() { return cur; }

	const _pair<key, info>& operator *() { return *cur; }
	const _pair<key, info>* operator ->() { return &*cur; }

	_map_iterator<key, info> operator ++ (int) {
		_map_iterator res(*this);
		++cur;
		return res;
	}
	_map_iterator<key, info>& operator ++() {
		++cur;
		return *this;
	}
	_map_iterator<key, info>& operator +(int num) {
		_map_iterator<key, info> result(cur + num);
		return result;
	}

	int operator != (const _map_iterator<key, info>& t_map_it) const{
		return cur != t_map_it.cur;
	}
	int operator == (const _map_iterator<key, info>& t_map_it) const{
		return cur == t_map_it.cur;
	}
};


template<class key, class info>
class _map {
private:
	int Size;
	_pair<key, info>* Data;
public:
	_map() : Size(0), Data(nullptr) {}
	_map(const _map<key, info>& t_map) : Size(t_map.Size), Data(new _pair<key, info>[t_map.Size]) {
		for (int i = 0; i < Size; i++)
			Data[i] = t_map.Data[i];
	}
	_map(_map<key, info>&& t_map) : Size(t_map.Size), Data(t_map.Data) {
		t_map.Data = nullptr;
	}
	~_map() {
		delete[] Data;
		Size = 0;
	}

	friend class _map_iterator<key, info>;

	typedef _map_iterator<key, info> _map_const_it;
	_map_const_it begin() const { return Data; }
	_map_const_it end() const { return Data + Size; }

	_map_const_it find(const key& t_key) const {
		_map_const_it it;
		for (it = begin(); it != end(); it++)
			if (it.get()->first == t_key)
				break;
		return it;
	}

	_map<key, info>& operator = (const _map<key, info>&);
	_map<key, info>& operator = (_map<key, info>&&);

	bool insert(const key& t_key, const info& t_info) {
		_map_const_it it = find(t_key);
		if (it == end() || Size == 0) {
			_pair<key, info>* t_Data;
			Size++;
			t_Data = new _pair<key, info>[Size];
			for (int i = 0; i < Size - 1; i++)
				t_Data[i] = Data[i];
			t_Data[Size - 1]._make_pair(t_key, t_info);
			delete[] Data;
			Data = t_Data;
			t_Data = nullptr;
			qsort(Data, 0, Size - 1);
			return true;
		}
		else {
			return false;
		}
	}

	void erase(const key& t_key) {
		_map_const_it it = find(t_key);
		if (it != end()) {
			_pair<key, info>* t_Data;
			t_Data = new _pair<key, info>[Size];
			for (int i = 0; i < Size; i++) {
				static int j = 0;
				if ((*it).first != Data[i].first) {
					t_Data[j] = Data[i];
					j++;
				}
			}
			Size--;
			delete[] Data;
			Data = t_Data;
			t_Data = nullptr;
		}
	}

	void clear() {
		Size = 0;
		delete[] Data;
		Data = nullptr;
	}

	int size() {
		return Size;
	}

	void qsort(_pair<key, info> t_Data[], int left, int right) {
		int l, r;
		_pair<key, info> tmp, mid;
		if (left < right) {
			l = left;
			r = right;
			mid = t_Data[(l + r) / 2];
			while (l <= r) {
				while (t_Data[l].first < mid.first)
					l++;
				while (t_Data[r].first > mid.first)
					r--;
				if (l <= r) {
					tmp = t_Data[l];
					t_Data[l] = t_Data[r];
					t_Data[r] = tmp;
					l++;
					r--;
				}
			}
			qsort(t_Data, left, r);
			qsort(t_Data, l, right);
		}
	}
};

template <class key, class info>
_map<key, info>& _map<key, info>::operator = (const _map<key, info>& t_map) {
	if (this != &t_map) {
		delete[] Data;
		Size = t_map.Size;
		Data = new _pair<key, info>[Size];
		for (int i = 0; i < Size; ++i)
			Data[i] = t_map.Data[i];
	}
	return *this;
}

template <class key, class info>
_map<key, info>& _map<key, info>::operator = (_map<key, info>&& t_map){
	if (this != &t_map) {
		delete[] Data;
		Size = t_map.Size;
		Data = t_map.Data;
		t_map.Data = nullptr;
	}
	return *this;
}

#endif

