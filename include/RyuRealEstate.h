#ifndef GUARD_RYUREALESTATE_H
#define GUARD_RYUREALESTATE_H


void DoDailyRealEstateTasks(void);

//bank tasks
void RyuBufferBankBalance(void);
void RyuBufferInterestGamestat(void);
int RyuFBDoDeposit(void);
int RyuFBDoWithdraw(void);

//property tasks
u16 RyuReturnPropertyValueFromID(u8 id);
u16 RyuReturnPropertyRentFromID(u8 id);
u16 CheckIfPlayerOwnsCurrentProperty(void);
bool32 CheckOwnedProperty(u32 id);
void RemoveProperty(u32 id);
void AddProperty(u32 id);
void doSpecialHouseWarp(void);
bool32 CheckRentedProperty(u32 id);
void VacateProperty(u32 id);
void LeaseProperty(u32 id);
void TryDamageproperties(void);
void RyuBufferRealEstateDetails(void);
void CollectRent(void);
void DecrementPropertyRepairTime(void);
void RyuResetRealEstateData(void);

#define NUM_PROPERTIES 12

#define PROPERTY_DEWFORD     0
#define PROPERTY_FALLARBOR   1
#define PROPERTY_LILYCOVE    2
#define PROPERTY_MAUVILLE    3
#define PROPERTY_OLDALE      4
#define PROPERTY_ROUTE119    5
#define PROPERTY_RUSTBURO    6
#define PROPERTY_SLATEPORT   7
#define PROPERTY_SNOWSHORE   8
#define PROPERTY_SOOTOPOLIS  9
#define PROPERTY_VERDANTURF  10
#define PROPERTY_MOSSDEEP    11
//there are an additional 20 properties

#define NUM_DAMAGE_TYPES 12//out of 14 max

#define DAMAGE_BROKEN_WINDOW         0
#define DAMAGE_DOORFRAME_BROKEN      1
#define DAMAGE_MINOR_ELECTRICAL      3
#define DAMAGE_WATER_MINOR           4
#define DAMAGE_LIGHTBULB_REPLACE     5
#define DAMAGE_MINOR_MECHANICAL      6
#define DAMAGE_FLOOR                 7
#define DAMAGE_APPLIANCE_REPLACE     8
#define DAMAGE_ELECTRICAL_MODERATE   9
#define DAMAGE_WATER_MODERATE        10
#define DAMAGE_MAJOR                 11


#endif //Real Estate header
