#include "stdafx.h"
#include "PyBridgeModelView.h"

void CPyBridgeModelView::Init(IBridgeModelViewController* pViewController,std::weak_ptr<ISelection> pSelection)
{
   m_pViewController = pViewController;
   m_pSelection = pSelection;
   CPyViewControllerBase::Init(pViewController);
}

void CPyBridgeModelView::GetGroupRange(GroupIndexType* pStartGroupIdx, GroupIndexType* pEndGroupIdx) const
{
   m_pViewController->GetGroupRange(pStartGroupIdx, pEndGroupIdx);
}

void CPyBridgeModelView::SetGroupRange(GroupIndexType startGroupIdx, GroupIndexType endGroupIdx)
{
   m_pViewController->SetGroupRange(startGroupIdx, endGroupIdx);
}

Float64 CPyBridgeModelView::GetCutStation() const
{
   return m_pViewController->GetCutStation();
}

void CPyBridgeModelView::SetCutStation(Float64 station)
{
   m_pViewController->SetCutStation(station);
}

void CPyBridgeModelView::SetViewMode(IBridgeModelViewController::ViewMode mode)
{
   m_pViewController->SetViewMode(mode);
}

IBridgeModelViewController::ViewMode CPyBridgeModelView::GetViewMode() const
{
   return m_pViewController->GetViewMode();
}

void CPyBridgeModelView::SetNorthUp(bool bNorthUp)
{
   m_pViewController->NorthUp(bNorthUp);
}

bool CPyBridgeModelView::GetNorthUp() const
{
   return m_pViewController->NorthUp();
}

void CPyBridgeModelView::SetShowLabels(bool bShowLabels)
{
   m_pViewController->ShowLabels(bShowLabels);
}

bool CPyBridgeModelView::GetShowLabels() const
{
   return m_pViewController->ShowLabels();
}

void CPyBridgeModelView::SetShowDimensions(bool bShowDimensions)
{
   m_pViewController->ShowDimensions(bShowDimensions);
}

bool CPyBridgeModelView::GetShowDimensions() const
{
   return m_pViewController->ShowDimensions();
}

void CPyBridgeModelView::SetShowBridge(bool bShowBridge)
{
   m_pViewController->ShowBridge(bShowBridge);
}

bool CPyBridgeModelView::GetShowBridge() const
{
   return m_pViewController->ShowBridge();
}

void CPyBridgeModelView::SetSchematic(bool bSchematic)
{
   m_pViewController->Schematic(bSchematic);
}

bool CPyBridgeModelView::GetSchematic() const
{
   return m_pViewController->Schematic();
}

void CPyBridgeModelView::ClearSelection()
{
   m_pSelection.lock()->ClearSelection();
}

PierIndexType CPyBridgeModelView::GetSelectedPier()
{
   return m_pSelection.lock()->GetSelectedPier();
}

SpanIndexType CPyBridgeModelView::GetSelectedSpan()
{
   return m_pSelection.lock()->GetSelectedSpan();
}

CGirderKey CPyBridgeModelView::GetSelectedGirder()
{
   return m_pSelection.lock()->GetSelectedGirder();
}

CSegmentKey CPyBridgeModelView::GetSelectedSegment()
{
   return m_pSelection.lock()->GetSelectedSegment();
}

bool CPyBridgeModelView::IsDeckSelected()
{
   return m_pSelection.lock()->IsDeckSelected();
}

bool CPyBridgeModelView::IsAlignmentSelected()
{
   return m_pSelection.lock()->IsAlignmentSelected();
}

bool CPyBridgeModelView::IsRailingSystemSelected(pgsTypes::TrafficBarrierOrientation orientation)
{
   return m_pSelection.lock()->IsRailingSystemSelected(orientation);
}

void CPyBridgeModelView::SelectPier(PierIndexType pierIdx)
{
   m_pSelection.lock()->SelectPier(pierIdx);
}

void CPyBridgeModelView::SelectSpan(SpanIndexType spanIdx)
{
   m_pSelection.lock()->SelectSpan(spanIdx);
}

void CPyBridgeModelView::SelectGirder(const CGirderKey& girderKey)
{
   m_pSelection.lock()->SelectGirder(girderKey);
}

void CPyBridgeModelView::SelectSegment(const CSegmentKey& segmentKey)
{
   m_pSelection.lock()->SelectSegment(segmentKey);
}

void CPyBridgeModelView::SelectDeck()
{
   m_pSelection.lock()->SelectDeck();
}

void CPyBridgeModelView::SelectAlignment()
{
   m_pSelection.lock()->SelectAlignment();
}

void CPyBridgeModelView::SelectRailingSystem(pgsTypes::TrafficBarrierOrientation orientation)
{
   m_pSelection.lock()->SelectRailingSystem(orientation);
}
