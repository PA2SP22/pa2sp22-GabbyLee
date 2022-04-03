#include "todo_item.h"

// Constuctor
TodoItem::TodoItem(string description, int priority, bool completed) {
    description_= description;
    priority_ = priority;
    completed_ = completed;
}

// Mutators
void TodoItem::set_description(string description) {
    description_ = description;
}

void TodoItem::set_priority(int priority) {
    if (priority > 5||priority < 1) {
        priority_ = 5;

    } else {
    priority_ = priority;
    }
}

void TodoItem::set_completed(bool completed) {
    completed_ = completed;
}

// Accessors
string TodoItem::description() const {
    return description_;
}

int TodoItem::priority() const {
    return priority_;
}

bool TodoItem::completed() const {
    return completed_;
}

string TodoItem::ToFile() {
stringstream ss;
ss << description_ << "@" << priority_ << "@" << completed_;
string scruby = Scrub(ss.str());
return ss.str();
}

string TodoItem::Scrub(string to_scrub) {
char to_replace = '@';
int i;
int size = to_scrub.length();
    for (i = 0; i < size; i++) {
        if (to_scrub.at(i) == to_replace) {
            to_scrub.at(i) ='`';
        }
    }
    return to_scrub;
}

