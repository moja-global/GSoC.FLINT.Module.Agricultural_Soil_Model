#pragma once
#include "moja/flint/example/agri/disturbanceevents.h"

#include <moja/flint/iflintdata.h>

#include <moja/dynamic.h>

namespace moja {
namespace flint {
namespace example {
namespace agri {

std::shared_ptr<flint::IFlintData> createFertEventsFactory(const std::string& eventTypeStr, int id,
                                                             const std::string& name, const DynamicObject& other);

class NFertEvent final : public DisturbanceEventBase {
  public:
   NFertEvent(int id, const std::string& name) : DisturbanceEventBase(id, "agri.NFertEvent", name) {}
   virtual ~NFertEvent() = default;

   void configure(DynamicObject config, const flint::ILandUnitController& landUnitController,
                  datarepository::DataRepository& dataRepository) override;
   DynamicObject exportObject() const override;
   void simulate(DisturbanceEventHandler& event_handler) const override;
   double quantity;
   int runtime;
};

class EmissionEvent final : public DisturbanceEventBase {
  public:
   EmissionEvent(int id, const std::string& name) : DisturbanceEventBase(id, "agri.EmissionEvent", name) {}
   virtual ~EmissionEvent() = default;

   void configure(DynamicObject config, const flint::ILandUnitController& landUnitController,
                  datarepository::DataRepository& dataRepository) override;
   DynamicObject exportObject() const override;
   void simulate(DisturbanceEventHandler& event_handler) const override;
   double quantity;
   int runtime;
};

class HarvestEvent final : public DisturbanceEventBase {
  public:
   HarvestEvent(int id, const std::string& name) : DisturbanceEventBase(id, "agri.HarvestEvent", name) {}
   virtual ~HarvestEvent() = default;

   void configure(DynamicObject config, const flint::ILandUnitController& landUnitController,
                  datarepository::DataRepository& dataRepository) override;
   DynamicObject exportObject() const override;
   void simulate(DisturbanceEventHandler& event_handler) const override;
   double yield_fresh;
   double above_ground_residue;
   float frac_burnt, frac_renew, frac_remove;
};

class ManureManagementEvent final : public DisturbanceEventBase {
  public:
   ManureManagementEvent(int id, const std::string& name) : DisturbanceEventBase(id, "agri.ManureManagementEvent", name) {}
   virtual ~ManureManagementEvent() = default;

   void configure(DynamicObject config, const flint::ILandUnitController& landUnitController,
                  datarepository::DataRepository& dataRepository) override;
   DynamicObject exportObject() const override;
   void simulate(DisturbanceEventHandler& event_handler) const override;
   std::vector<DynamicVar> animal_type, productivity_class, use, no_livestock;
   double N_cdg, N_bedding, frac_feed, frac_cnst, frac_fuel;
};

class PlantEvent final : public DisturbanceEventBase {
  public:
   PlantEvent(int id, const std::string& name) : DisturbanceEventBase(id, "agri.PlantEvent", name) {}
   virtual ~PlantEvent() = default;

   void configure(DynamicObject config, const flint::ILandUnitController& landUnitController,
                  datarepository::DataRepository& dataRepository) override;
   DynamicObject exportObject() const override;
   void simulate(DisturbanceEventHandler& event_handler) const override;
   std::string crop_type;
};

}  // namespace agri
}  // namespace example
}  // namespace flint
}  // namespace moja