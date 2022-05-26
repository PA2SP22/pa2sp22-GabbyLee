#include "magic_item.h"
// Constructor / Destructor
MagicItem::MagicItem() {
set_name("magicitem");
set_value(0);
description_ = "no description";
mana_required_ = 0;
}


MagicItem::MagicItem(string name, unsigned int value,
           string descript, unsigned int mana_required) {
set_name(name);
set_value(value);
description_ = descript;
mana_required_ = mana_required;
}

MagicItem::~MagicItem() {
}

// Setters
void MagicItem::set_description(string descript) {
description_ = descript;
}

void MagicItem::set_mana_required(unsigned int mana) {
mana_required_ = mana;
}

// Getters
string MagicItem::description() {
return description_;
}

unsigned int MagicItem::mana_required() {
return mana_required_;
}

// public function
string MagicItem::ToString() {
stringstream print;
print << Item::ToString();
print << ", " << description() << ", requires " << mana_required() << " mana";
return print.str();
}
