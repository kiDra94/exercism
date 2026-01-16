#ifndef DOCTOR_DATA_H_INCLUDED
#define DOCTOR_DATA_H_INCLUDED
#include <string>

namespace star_map {
    enum class System {
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani,
    };
}

namespace heaven {
    class Vessel {
    public:
      Vessel(std::string name, int gen) : generation(gen), name_(name) {}
      Vessel(std::string name, int gen, star_map::System sys_name) :
      generation(gen), current_system(sys_name), name_(name) {}
      Vessel replicate(std::string name) const;
      int generation{0};
      star_map::System current_system{star_map::System::Sol};
      int busters{0};
      void make_buster() {busters ++;};
      bool shoot_buster();
      std::string get_name() {return name_;};
    private:
        std::string name_{""};
    };

    std::string get_older_bob(Vessel a, Vessel b);
    bool in_the_same_system(Vessel a, Vessel b);
} // end of namespace heaven


#endif // DOCTOR_DATA_H_INCLUDED
