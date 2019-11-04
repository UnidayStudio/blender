#pragma once

#include "SG_QList.h"

class SG_NodeInterface {
public:
	SG_NodeInterface() {}
	virtual ~SG_NodeInterface(){}

	void SetParent(SG_NodeInterface* parent) = 0;
	SG_NodeInterface* GetParent() = 0;
	
	static SG_NodeInterface* GetNextScheduled(SG_QList& head) = 0;
private:
}
