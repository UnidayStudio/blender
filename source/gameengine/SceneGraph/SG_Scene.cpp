#include "SG_Scene.h"

#include "CM_List.h"

#include "BLI_utildefines.h"

void SG_Scene::Schedule(SG_NodeInterface *node)
{
	node->Schedule(m_head);
}

void SG_Scene::Reschedule(SG_NodeInterface *node)
{
	node->Reschedule(m_head);
}

void SG_Scene::AddRootNode(SG_NodeInterface *node)
{
	m_rootNodes.push_back(node);
}

void SG_Scene::RemoveRootNode(SG_NodeInterface *node)
{
	CM_ListRemoveIfFound(m_rootNodes, node);
}

void SG_Scene::DestructRootNodes()
{
	while (!m_rootNodes.empty()) {
		delete m_rootNodes.front();
	}
}

void SG_Scene::UpdateParents()
{
	// We use the SG dynamic list
	SG_NodeInterface *node;

	while ((node = SG_NodeInterface::GetNextScheduled(m_head))) {
		node->UpdateWorldData();
	}

	// The list must be empty here
	BLI_assert(m_head.Empty());
	// Some nodes may be ready for reschedule, move them to schedule list for next time.
	while ((node = SG_NodeInterface::GetNextRescheduled(m_head))) {
		node->Schedule(m_head);
	}
}

void SG_Scene::Merge(SG_Scene *other)
{
	// Change scene of merge nodes.
	for (SG_NodeInterface *node : other->m_rootNodes) {
		node->ReplaceScene(this);
	}

	m_rootNodes.insert(m_rootNodes.begin(), other->m_rootNodes.begin(), other->m_rootNodes.end());
}
