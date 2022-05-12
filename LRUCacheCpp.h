#pragma once
#include <list>
#include <iostream>
#include <unordered_map>


namespace Cache {
	template<class T>
	class LRUCache
	{
	public:
		typedef size_t size_type;
		typedef T value_type;
		LRUCache(const LRUCache&) = delete;
		LRUCache(LRUCache&&) = delete;
		LRUCache(size_type n)
			:_size(n)
		{}
		void setCacheSize(size_type n) {
			_size = n;
		}
		LRUCache& operator=(const LRUCache&) = delete;

		void refer(value_type n) {
			if (_cache.find(n) == _cache.end()) {
				if (_deq.size() == _size) {
					value_type _last = _deq.back();
					_deq.pop_back();
					_cache.erase(_last);
				}
			}
			else _deq.erase(_cache[n]);
			_deq.push_front(n);
			_cache[n] = _deq.begin();
		}
		void display()
		{
			std::cout << std::endl;
			for (decltype(_deq.begin()) it = _deq.begin(); it != _deq.end(); it++) {
				std::cout << *it << " ";
			}
			std::cout << std::endl;
		}
	private:

		std::list<value_type> _deq;
		std::unordered_map < value_type,decltype(_deq.begin()) > _cache;
		size_type _size;
	};

};
