#include "stdafx.h"
#include "PyBridge.h"

void CPyBridge::Init(std::weak_ptr<WBFL::EAF::Broker> pBroker)
{
   auto broker = pBroker.lock();
   m_pBridge = broker->GetInterface<IBridge>(IID_IBridge);
}

void CPyBridge::Reset()
{
}

bool CPyBridge::HasAsymmetricGirders() const
{
   return m_pBridge.lock()->HasAsymmetricGirders();
}

bool CPyBridge::HasTiltedGirders() const
{
   return m_pBridge.lock()->HasTiltedGirders();
}

Float64 CPyBridge::GetAlignmentOffset() const
{
   return m_pBridge.lock()->GetAlignmentOffset();
}

Float64 CPyBridge::GetLength() const
{
   return m_pBridge.lock()->GetLength();
}

Float64 CPyBridge::GetNominalSpanLength(SpanIndexType spanIdx) const
{
   return m_pBridge.lock()->GetSpanLength(spanIdx);
}

SpanIndexType CPyBridge::GetSpanCount() const
{
   return m_pBridge.lock()->GetSpanCount();
}

PierIndexType CPyBridge::GetPierCount() const
{
   return m_pBridge.lock()->GetPierCount();
}

SupportIndexType CPyBridge::GetTemporarySupportCount() const
{
   return m_pBridge.lock()->GetTemporarySupportCount();
}

GroupIndexType CPyBridge::GetGirderGroupCount() const
{
   return m_pBridge.lock()->GetGirderGroupCount();
}

GirderIndexType CPyBridge::GetGirderlineCount() const
{
   return m_pBridge.lock()->GetGirderlineCount();
}

GirderIndexType CPyBridge::GetGirderCount(GroupIndexType grpIdx) const
{
   return m_pBridge.lock()->GetGirderCount(grpIdx);
}

GirderIndexType CPyBridge::GetGirderCountBySpan(SpanIndexType spanIdx) const
{
   return m_pBridge.lock()->GetGirderCountBySpan(spanIdx);
}

PierIndexType CPyBridge::GetGirderGroupStartPier(GroupIndexType grpIdx) const
{
   return m_pBridge.lock()->GetGirderGroupStartPier(grpIdx);
}

PierIndexType CPyBridge::GetGirderGroupEndPier(GroupIndexType grpIdx) const
{
   return m_pBridge.lock()->GetGirderGroupEndPier(grpIdx);
}

SpanIndexType CPyBridge::GetGirderGroupStartSpan(GroupIndexType grpIdx) const
{
   return m_pBridge.lock()->GetGirderGroupStartSpan(grpIdx);
}

SpanIndexType CPyBridge::GetGirderGroupEndSpan(GroupIndexType grpIdx) const
{
   return m_pBridge.lock()->GetGirderGroupEndSpan(grpIdx);
}

GroupIndexType CPyBridge::GetGirderGroupIndex(SpanIndexType spanIdx) const
{
   return m_pBridge.lock()->GetGirderGroupIndex(spanIdx);
}

Float64 CPyBridge::GetSpanLength(const CSpanKey& spanKey) const
{
   return m_pBridge.lock()->GetSpanLength(spanKey);
}

Float64 CPyBridge::GetFullSpanLength(const CSpanKey& spanKey) const
{
   return m_pBridge.lock()->GetFullSpanLength(spanKey);
}

Float64 CPyBridge::GetGirderlineLength(GirderIndexType gdrLineIdx) const
{
   return m_pBridge.lock()->GetGirderlineLength(gdrLineIdx);
}

Float64 CPyBridge::GetGirderLayoutLength(const CGirderKey& girderKey) const
{
   return m_pBridge.lock()->GetGirderLayoutLength(girderKey);
}

Float64 CPyBridge::GetGirderSpanLength(const CGirderKey& girderKey) const
{
   return m_pBridge.lock()->GetGirderSpanLength(girderKey);
}

Float64 CPyBridge::GetGirderLength(const CGirderKey& girderKey) const
{
   return m_pBridge.lock()->GetGirderLength(girderKey);
}

Float64 CPyBridge::GetCantileverLength(const CSpanKey& spanKey, pgsTypes::MemberEndType endType) const
{
   return m_pBridge.lock()->GetCantileverLength(spanKey, endType);
}

SegmentIndexType CPyBridge::GetSegmentCount(const CGirderKey& girderKey) const
{
	return m_pBridge.lock()->GetSegmentCount(girderKey);
}

Float64 CPyBridge::GetSegmentLength(const CSegmentKey& segmentKey) const
{
   return m_pBridge.lock()->GetSegmentLength(segmentKey);
}

Float64 CPyBridge::GetSegmentSpanLength(const CSegmentKey& segmentKey) const
{
   return m_pBridge.lock()->GetSegmentSpanLength(segmentKey);
}

Float64 CPyBridge::GetSegmentLayoutLength(const CSegmentKey& segmentKey) const
{
   return m_pBridge.lock()->GetSegmentLayoutLength(segmentKey);
}

Float64 CPyBridge::GetSegmentFramingLength(const CSegmentKey& segmentKey) const
{
   return m_pBridge.lock()->GetSegmentFramingLength(segmentKey);
}

Float64 CPyBridge::GetSegmentPlanLength(const CSegmentKey& segmentKey) const
{
   return m_pBridge.lock()->GetSegmentPlanLength(segmentKey);
}

Float64 CPyBridge::GetSegmentStartEndDistance(const CSegmentKey& segmentKey) const
{
   return m_pBridge.lock()->GetSegmentStartEndDistance(segmentKey);
}

Float64 CPyBridge::GetSegmentEndEndDistance(const CSegmentKey& segmentKey) const
{
   return m_pBridge.lock()->GetSegmentEndEndDistance(segmentKey);
}

Float64 CPyBridge::GetSegmentStartBearingOffset(const CSegmentKey& segmentKey) const
{
   return m_pBridge.lock()->GetSegmentStartBearingOffset(segmentKey);
}

Float64 CPyBridge::GetSegmentEndBearingOffset(const CSegmentKey& segmentKey) const
{
   return m_pBridge.lock()->GetSegmentEndBearingOffset(segmentKey);
}

Float64 CPyBridge::GetSegmentStartSupportWidth(const CSegmentKey& segmentKey) const
{
   return m_pBridge.lock()->GetSegmentStartSupportWidth(segmentKey);
}

Float64 CPyBridge::GetSegmentEndSupportWidth(const CSegmentKey& segmentKey) const
{
   return m_pBridge.lock()->GetSegmentEndSupportWidth(segmentKey);
}

bool CPyBridge::ModelCantilever(const CSegmentKey& segmentKey, pgsTypes::MemberEndType endType) const
{
   bool bLeft, bRight;
   m_pBridge.lock()->ModelCantilevers(segmentKey, &bLeft, &bRight);
   return (endType == pgsTypes::metStart ? bLeft : bRight);
}

Float64 CPyBridge::GetSegmentSlope(const CSegmentKey& segmentKey) const
{
   return m_pBridge.lock()->GetSegmentSlope(segmentKey);
}

Float64 CPyBridge::GetSlabOffset(const CSegmentKey& segmentKey, pgsTypes::MemberEndType end) const
{
   return m_pBridge.lock()->GetSlabOffset(segmentKey,end);
}

Float64 CPyBridge::GetElevationAdjustment(IntervalIndexType intervalIdx, const pgsPointOfInterest& poi) const
{
   return m_pBridge.lock()->GetElevationAdjustment(intervalIdx, poi);
}

Float64 CPyBridge::GetRotationAdjustment(IntervalIndexType intervalIdx, const pgsPointOfInterest& poi) const
{
   return m_pBridge.lock()->GetRotationAdjustment(intervalIdx, poi);
}

Float64 CPyBridge::GetCLPierToCLBearingDistance(const CSegmentKey& segmentKey, pgsTypes::MemberEndType endType, pgsTypes::MeasurementType measure) const
{
   return m_pBridge.lock()->GetCLPierToCLBearingDistance(segmentKey, endType, measure);
}

Float64 CPyBridge::GetCLPierToSegmentEndDistance(const CSegmentKey& segmentKey, pgsTypes::MemberEndType endType, pgsTypes::MeasurementType measure) const
{
   return m_pBridge.lock()->GetCLPierToSegmentEndDistance(segmentKey, endType, measure);
}

