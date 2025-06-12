#include "stdafx.h"
#include "PyLossParameters.h"

void CPyLossParameters::Init(std::weak_ptr<WBFL::EAF::Broker> pBroker)
{
   auto broker = pBroker.lock();
   m_pLossParameters = broker->GetInterface<ILossParameters>(IID_ILossParameters);
}

void CPyLossParameters::Reset()
{
}

PrestressLossCriteria::LossMethodType CPyLossParameters::GetLossMethod() const
{
   return m_pLossParameters.lock()->GetLossMethod();
}

PrestressLossCriteria::TimeDependentConcreteModelType CPyLossParameters::GetTimeDependentModel() const
{
   return m_pLossParameters.lock()->GetTimeDependentModel();
}

void CPyLossParameters::SetIgnoreCreepEffects(bool bIgnore)
{
   m_pLossParameters.lock()->IgnoreCreepEffects(bIgnore);
}

bool CPyLossParameters::GetIgnoreCreepEffects() const
{
   return m_pLossParameters.lock()->IgnoreCreepEffects();
}

void CPyLossParameters::SetIgnoreShrinkageEffects(bool bIgnore)
{
   m_pLossParameters.lock()->IgnoreShrinkageEffects(bIgnore);
}

bool CPyLossParameters::GetIgnoreShrinkageEffects() const
{
   return m_pLossParameters.lock()->IgnoreShrinkageEffects();
}

void CPyLossParameters::SetIgnoreRelaxationEffects(bool bIgnore)
{
   m_pLossParameters.lock()->IgnoreRelaxationEffects(bIgnore);
}

bool CPyLossParameters::GetIgnoreRelaxationEffects() const
{
   return m_pLossParameters.lock()->IgnoreRelaxationEffects();
}

void CPyLossParameters::SetIgnoreTimeDependentEffects(bool bIgnoreCreep, bool bIgnoreShrinkage, bool bIgnoreRelaxation)
{
   m_pLossParameters.lock()->IgnoreTimeDependentEffects(bIgnoreCreep, bIgnoreShrinkage, bIgnoreRelaxation);
}

void CPyLossParameters::SetTendonPostTensionParameters(Float64 Dset, Float64 wobble, Float64 friction)
{
   m_pLossParameters.lock()->SetTendonPostTensionParameters(Dset, wobble, friction);
}

void CPyLossParameters::GetTendonPostTensionParameters(Float64* Dset, Float64* wobble, Float64* friction) const
{
   m_pLossParameters.lock()->GetTendonPostTensionParameters(Dset, wobble, friction);
}

void CPyLossParameters::SetTemporaryStrandPostTensionParameters(Float64 Dset, Float64 wobble, Float64 friction)
{
   m_pLossParameters.lock()->SetTemporaryStrandPostTensionParameters(Dset, wobble, friction);
}

void CPyLossParameters::GetTemporaryStrandPostTensionParameters(Float64* Dset, Float64* wobble, Float64* friction) const
{
   m_pLossParameters.lock()->GetTemporaryStrandPostTensionParameters(Dset, wobble, friction);
}

void CPyLossParameters::SetUseGeneralLumpSumLosses(bool bLumpSum)
{
   m_pLossParameters.lock()->UseGeneralLumpSumLosses(bLumpSum);
}

bool CPyLossParameters::GetUseGeneralLumpSumLosses() const
{
   return m_pLossParameters.lock()->UseGeneralLumpSumLosses();
}

Float64 CPyLossParameters::GetBeforeXferLosses() const
{
   return m_pLossParameters.lock()->GetBeforeXferLosses();
}

void CPyLossParameters::SetBeforeXferLosses(Float64 loss)
{
   m_pLossParameters.lock()->SetBeforeXferLosses(loss);
}

Float64 CPyLossParameters::GetAfterXferLosses() const
{
   return m_pLossParameters.lock()->GetAfterXferLosses();
}

void CPyLossParameters::SetAfterXferLosses(Float64 loss)
{
   m_pLossParameters.lock()->SetAfterXferLosses(loss);
}

Float64 CPyLossParameters::GetLiftingLosses() const
{
   return m_pLossParameters.lock()->GetLiftingLosses();
}

void CPyLossParameters::SetLiftingLosses(Float64 loss)
{
   m_pLossParameters.lock()->SetLiftingLosses(loss);
}

Float64 CPyLossParameters::GetShippingLosses() const
{
   return m_pLossParameters.lock()->GetShippingLosses();
}

void CPyLossParameters::SetShippingLosses(Float64 loss)
{
   m_pLossParameters.lock()->SetShippingLosses(loss);
}

Float64 CPyLossParameters::GetBeforeTempStrandRemovalLosses() const
{
   return m_pLossParameters.lock()->GetBeforeTempStrandRemovalLosses();
}

void CPyLossParameters::SetBeforeTempStrandRemovalLosses(Float64 loss)
{
   m_pLossParameters.lock()->SetBeforeTempStrandRemovalLosses(loss);
}

Float64 CPyLossParameters::GetAfterTempStrandRemovalLosses() const
{
   return m_pLossParameters.lock()->GetAfterTempStrandRemovalLosses();
}

void CPyLossParameters::SetAfterTempStrandRemovalLosses(Float64 loss)
{
   m_pLossParameters.lock()->SetAfterTempStrandRemovalLosses(loss);
}

Float64 CPyLossParameters::GetAfterDeckPlacementLosses() const
{
   return m_pLossParameters.lock()->GetAfterDeckPlacementLosses();
}

void CPyLossParameters::SetAfterDeckPlacementLosses(Float64 loss)
{
   m_pLossParameters.lock()->SetAfterDeckPlacementLosses(loss);
}

Float64 CPyLossParameters::GetAfterSIDLLosses() const
{
   return m_pLossParameters.lock()->GetAfterSIDLLosses();
}

void CPyLossParameters::SetAfterSIDLLosses(Float64 loss)
{
   m_pLossParameters.lock()->SetAfterSIDLLosses(loss);
}

Float64 CPyLossParameters::GetFinalLosses() const
{
   return m_pLossParameters.lock()->GetFinalLosses();
}

void CPyLossParameters::SetFinalLosses(Float64 loss)
{
   m_pLossParameters.lock()->SetFinalLosses(loss);
}
