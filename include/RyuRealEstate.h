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


#endif //Real Estate header
