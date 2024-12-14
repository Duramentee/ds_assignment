#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <utility>

template <typename KeyType, typename ValueType>
class HashTable {
public:
	using value_type = std::pair<KeyType, ValueType>;
	using container_type = std::list<value_type>;
	using table_type = std::vector<container_type>;

	explicit HashTable(size_t size = 10) : table_{size}, num_elements_{0} {}

	void insert(const KeyType& key, const ValueType& value) {
		auto index = hash_function(key);
		for (auto& pair : table_[index]) {
			// 存在则更新
			if (pair.first == key) {
				pair.second = value;
				return;
			}
		}
		table_[index].emplace_back(key, value);
		++num_elements_;
	}

	bool find(const KeyType& key, ValueType& value) const {
		auto index = hash_function(key);
		for (const auto& pair : table_[index]) {
			if (pair.first == key) {
				value = pair.second;
				return true;
			}
		}
		return false;
	}

	bool remove(const KeyType& key) {
		auto index = hash_function(key);
		for (auto it = table_[index].begin(); it != table_[index].end(); ++it) {
			if (it->first == key) {
				table_[index].erase(it);
				--num_elements_;
				return true;
			}
		}
		return false;
	}

private:
	// hash function
	size_t hash_function(const KeyType& key) const {
		// using c++ 11 hash function
		std::hash<KeyType> hasher;
		return hasher(key) % table_.size();
	}

	table_type table_;
	size_t num_elements_;
};
