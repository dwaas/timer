#include <iostream>
#include <boost/program_options.hpp>
#include <utility> //std::pair
#include <iterator> //std::ostream_iterator
#include <map> //std::map
#include <string> //std::string
#include <vector> //std::vector


//#include <chrono>
//#include <boost/interprocess/shared_memory_object.hpp>

namespace po = boost::program_options;
//?
using TimerList = std::vector<std::string>;
using TimerMap = std::map<std::string, int>;

std::ostream& operator<<(std::ostream& os, const TimerList& tl){

        std::copy(tl.begin(), tl.end(),
                        std::ostream_iterator<std::string>(os, " "));
        return os;
}

auto main(int ac, char* av[])-> int{
        auto general = po::options_description{"Allowed options"};

        general.add_options()
                ("help,h", "produce help message")
                ("set,s", po::value<int>(), "set timer length in seconds");

        auto hidden = po::options_description{};
        hidden.add_options()
                ("get", po::value<TimerList>(), "get timer status");

        auto cli_options = po::options_description{};
        cli_options.add(general).add(hidden);

        auto vm = po::variables_map{};

        auto p = po::positional_options_description{};

        p.add("get", -1);

        po::store(po::command_line_parser(ac, av).options(cli_options).positional(p).run(),
                vm);

        po::notify(vm);

        if(vm.count("help")){
                std::cout << general << "\n";
                return 1;
        }

        if(vm.count("set")){
                std::cout << "A timer named next_meeting will notify you in "
                  << vm["set"].as<int> () << "seconds." << "\n";
        }

// queries to existing timers
        if(vm.empty()){
                //if they exist, print timers,
                //else say that they do not exist and exit.
                std::cout << "Placeholder for existing timers" << "\n";
                return 1;
        }

        if(vm.count("get")){
                std::cout << vm["get"].as<TimerList>() << "\n";
        }
}

