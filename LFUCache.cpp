#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;

struct Node {
	int key = 0;
	int value = 0;
	int freq = 0;
	int timeStamp= 0;
};

struct SetComparator {
	bool operator()(const Node &a1, const Node &a2) const{
		if (a1.freq == a2.freq) {
			return a1.timeStamp < a2.timeStamp;
		}
		return a1.freq < a2.freq;
	}
};

class LFUCache {
public:
	int fullCap;
	int curCap;
	int time;
	unordered_map<int,Node>cacheMap;
	set<Node, SetComparator>cacheSet;
	set<Node, SetComparator> ::iterator sit;

	LFUCache(int capacity) {
		fullCap = capacity;
		curCap = 0;
		time = 0;
		cacheMap.clear();
		cacheSet.clear();
	}

	int get(int key) {
		if (cacheMap.count(key) > 0) {
			Update(key, cacheMap[key].value);
			return cacheMap[key].value;
		}
		return -1;
	}

	void Update(int key, int value) {
		Node curNode = cacheMap[key];
		cacheSet.erase(curNode);

		curNode.timeStamp = ++time;
		curNode.value = value;
		curNode.freq += 1;

		cacheSet.insert(curNode);
		cacheMap[key] = curNode;
	}

	void Add(int key, int value) {
		Node tempNode;
		//ADD
		tempNode.key = key;
		tempNode.freq = 1;
		tempNode.timeStamp = ++time;
		tempNode.value = value;
		cacheMap[key] = tempNode;
		cacheSet.insert(tempNode);
		curCap++;
	}

	void Remove() {
		if (cacheSet.size() > 0) {
			curCap--;
			sit = cacheSet.begin();
			Node nd = *sit;
			cacheSet.erase(nd);
			cacheMap.erase(nd.key);
		}
	}

	void put(int key, int value) {
		if (fullCap == 0) {
			return;
		}
		if (curCap < fullCap) {
			// no need to delete, just add and edit
			if (cacheMap.count(key) == 0) {
				Add(key, value);
			}
			else {
				Update(key, value);
			}
		}
		else {
			if (cacheMap.count(key) == 0) {
				Remove();
				Add(key, value);
			}
			else {
				Update(key, value);
			}
		}
	}
};
int main() {

	LFUCache obj = LFUCache(2);
	obj.put(1, 1);
	obj.put(2, 2);
	cout<<obj.get(1)<<"\n";
	obj.put(3, 3);
	cout << obj.get(2) << "\n";

	return 0;
}
