#ifndef conhash_INCLUDED
#define conhash_INCLUDED

#include <string>

/* nodes structure */
class node_s
{
public:
	char iden[64]; /* node name or some thing identifies the node */
	unsigned int replicas; /* number of replica virtual nodes */
	node_s(){}
	node_s(char *str, int replicas)
	{
		this->replicas = replicas;
		strncpy(iden, str, sizeof(iden));
	}
	void setNode(char *str, int replicas)
	{
		this->replicas = replicas;
		strncpy(iden, str, sizeof(iden));
	}
};

class virtual_node_s
{
public:
	unsigned int index;
	node_s *node;
	virtual_node_s(){ index = 0; node = NULL; }
	virtual_node_s(node_s *node, unsigned int index)
	{
		this->index = index;
		this->node = node;
	}
	void setVirtualNode(node_s *node, unsigned int index)
	{
		this->index = index;
		this->node = node;
	}
	std::string toString() const{
		char buff[128];
		_snprintf_s(buff, 127, _TRUNCATE, "%s-%03d", node->iden, index);
		int length = strlen(buff);
		return std::string(buff, buff + length);
	}
};

#endif