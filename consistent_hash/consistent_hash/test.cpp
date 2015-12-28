#include <iostream>
#include "conhash.h"
#include <string>
#include "consistent_hash.h"
#include "conhash_util.h"
#include "conhash_inter.h"

struct md5_hasher{
	unsigned int operator()(const virtual_node_s &node){
		std::string str = node.toString();
		unsigned int hash = __conhash_hash_def(str.c_str());
		return hash;
		
	}
	typedef unsigned int result_type;
};

int main()
{
	typedef consistent_hash_map<virtual_node_s, md5_hasher> consistent_hash_t;
	char buff[128];
	consistent_hash_t conhash;
	node_s node[16];
	node[0].setNode("titanic", 32);
	node[1].setNode("terminator2018", 24);
	node[2].setNode("Xenomorph", 25);
	node[3].setNode("True Lies", 10);
	node[4].setNode("avantar", 48);
	virtual_node_s virtual_node;
	for (int i = 0; i < 5; ++i){
		for (unsigned int j = 0; j < node[i].replicas; ++j){
			virtual_node.setVirtualNode(&node[i], j);
			conhash.insert(virtual_node);
		}
	}
	printf("virtual nodes number %d\n", conhash.size());
	
	printf("the hashing results--------------------------------------:\n");
	/* try object */
	for (int i = 0; i < 20; i++)
	{
		sprintf(buff, "James.km%03d", i);
		unsigned int hash = __conhash_hash_def(buff);
		auto it = conhash.find(hash);
		if (it == conhash.end())
			std::cout << "not found, consistent_hash is empty" << std::endl;
		else
			std::cout << buff << "is in node " << it->second.node->iden<< "\n";
	}

	int del = 2;
	for (unsigned int j = 0; j < node[del].replicas; ++j){
		virtual_node.setVirtualNode(&node[del], j);
		conhash.erase(virtual_node);
	}
	
	printf("remove node[%s], virtual nodes number %d\n", node[2].iden, conhash.size());
	printf("the hashing results--------------------------------------:\n");
	for (int i = 0; i < 20; i++)
	{
		sprintf(buff, "James.km%03d", i);
		unsigned int hash = __conhash_hash_def(buff);
		auto it = conhash.find(hash);
		if (it == conhash.end())
			std::cout << "not found, consistent_hash is empty" << std::endl;
		else
			std::cout << buff << "is in node " << it->second.node->iden << "\n";
	}

	return 0;
}