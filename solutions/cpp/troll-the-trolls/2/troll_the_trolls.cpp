//#include "troll_the_trolls.hpp"
namespace hellmath {

enum class AccountStatus {
    troll,
    guest,
    user,
    mod,
    };
enum class Action {
    read,
    write,
    remove,
    };

bool display_post(AccountStatus poster, AccountStatus viewer) {
    switch (poster) {
        case AccountStatus::troll:
            return (viewer == AccountStatus::troll);

        case AccountStatus::guest:
        case AccountStatus::user:
        case AccountStatus::mod:
            return true;
    }
    return false;
}

bool permission_check(Action a, AccountStatus as){
    switch(as){
        case AccountStatus::guest: {
            return Action::read == a;
        }
        case AccountStatus::user:
        case AccountStatus::troll: {
            return (Action::read == a || Action::write == a);
        }
        case AccountStatus::mod: {
            return true;
        }
        default: {
            return false;
        }
    };
}

bool valid_player_combination(AccountStatus first, AccountStatus second) {
    switch (first) {
        case AccountStatus::guest:
            return false;

        case AccountStatus::troll:
            switch (second) {
                case AccountStatus::troll:
                    return true;
                default:
                    return false;
            }

        case AccountStatus::user:
        case AccountStatus::mod:
            switch (second) {
                case AccountStatus::guest:
                    return false;
                case AccountStatus::troll:
                    return false;
                case AccountStatus::user:
                case AccountStatus::mod:
                    return true;
            }
    }
    return false;
}

bool has_priority(AccountStatus a, AccountStatus b) {
    switch (a) {
        case AccountStatus::mod:
            return (b != AccountStatus::mod);

        case AccountStatus::user:
            return (b == AccountStatus::guest || b == AccountStatus::troll);

        case AccountStatus::guest:
            return (b == AccountStatus::troll);

        case AccountStatus::troll:
            return false;
    }
    return false;
}

}  // namespace hellmath
















