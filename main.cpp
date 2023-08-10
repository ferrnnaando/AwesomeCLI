#include "header.h"
#include "structure/structure.h"
#include "encrypt/encrypt.h"

//<filesystem> what is lol

void stress();

int main(int argc, char* argv[]) {
    prefix::entered_exec_name = argv[0];
    is_integer integer;

    if(prefix::entered_exec_name.find(prefix::program_name) == std::string::npos) {
        std::cerr << error << "El nombre del ejecutable debe ser \"" + prefix::program_name + "\". Por favor, no trate de modificar ni distribuir este programa." << std::endl;
        return 1;
    } 
    else {
        if(is_sudo()) {
             if (!files_exists("/awesome-cli/")) {
                config_files();
            }
        }
        else {
           std::cerr << ANSI_YELLOW << "Uso: sudo ./awesome-cli --help\n";
            return 1;
        }

        switch (argc) {
            case 1: //tells how to do a good usage if the user just did ./awesome-cli
                std::cerr << ANSI_YELLOW << "Uso: sudo ./" + prefix::program_name + " --help" << std::endl;
                return 1;

            default: //if the user entered a parameter, let register it and value it below.
                if (argv[1] == prefix::long_prefix + "help" || argv[1] == prefix::short_prefix + "h") { //|| allows to check for long command version prefix and the alias.
                    switch (argc) {
                        case 2:
                            std::cout << ANSI_RESET << commands::description::help_description; //print the main help const char message
                            return 0;

                        case 3:
                            if(std::string(argv[2]) == "help") {
                                std::cerr << error << "¿Quisiste decir --help?" << std::endl;
                                return 1;
                            }
                            if (std::string(argv[2]) == "search") {
                                std::cout << commands::description::help_search;
                                return 0;
                            }
                            else if(std::string(argv[2]) == "track") {
                                std::cout << commands::description::help_track;
                            }
                            else if(std::string(argv[2]) == "stress") {
                                std::cout << commands::description::help_stress;
                            }
                            else {
                                std::cerr << error << "El comando indicado no existe. ¿Quisiste decir --help?" << std::endl;
                                return 1;
                            }
                            break; 

                        default:
                            if (argc >= 4) {
                                std::cerr << error << "Has indicado más parámetros de los necesarios. ¿Quisiste decir --help <command>?" << std::endl;
                                return 1;
                            } else {
                                std::cerr << error << "Error inesperado." << std::endl;
                                return 1;
                            }
                    }
                }
                else if(argv[1] == prefix::long_prefix + "search" || argv[1] == prefix::short_prefix + "s") {
                    //std::__is_nothrow_uses_allocator_constructiblees

                    std::string line;

                    bool found = false;
                    int lineNum = 0;
                    std::vector<int> found_multiple;

                    std::string keyword;
                    std::string search = argv[2];
                    std::ifstream file(search);

                    switch(argc) {
                    case 2:
                        std::cerr << "Uso: " << commands::description::help_search;
                        std::cerr << error << "           ^~~~~~~~~~~~~~~~~~" << std::endl;
                        std::cerr << ANSI_RED << "Parámetros insuficientes para " << argv[1] << ". (2 restantes)" << std::endl; //set --search or -s for a more friendly-interact
                        return 1;
                    case 3:
                        std::cerr << "Uso: " << commands::description::help_search;
                        std::cerr << error << "                     ^~~~~~~~" << std::endl;
                        std::cerr << ANSI_RED << "Parámetros insuficientes para " << argv[1] << ". (1 restante)" << std::endl;
                        return 1;
                    case 4:
                        if (!file) {
                            std::cerr << error << "El archivo " << argv[2] << " no existe, asegúrate de indicar el formato de ruta correctamente." << std::endl;
                            return 1;
                        } else {
                            while (std::getline(file, line)) {
                                lineNum++;
                                if (line.find(argv[3]) != std::string::npos) {
                                    found = true;
                                    found_multiple.push_back(lineNum);
                                    break;
                                }
                            }

                            if (found) {
                                std::cout << "Informacion:\n  Palabra clave: " << argv[3] << ",\n";
                                for(int lineNum : found_multiple) {
                                    std::cout << " Linea: " << lineNum << " || Contenido: " << line << std::endl;
                                }
                                return 0;
                            } else {
                                std::cerr << error << "La palabra clave introducida no existe en el archivo existente." << std::endl;
                                return 1;
                            }
                        }

                    default:
                        if(argc >= 5){
                            std::cerr << error << "Has indicado más parámetros de los necesarios. ¿Quisiste decir --help search?" << std::endl;
                            return 1;
                        } else {
                            std::cerr << error << "Error inesperado.";
                            return 1;
                        }
                    }
                }
                else if(argv[1] == prefix::long_prefix + "version" || argv[1] == prefix::short_prefix + "v") {
                    std::cout << commands::description::version_description;
                    return 0;
                }
                else if(argv[1] == prefix::long_prefix + "config") {
                   switch (argc) {
                    case 2:
                        std::cout << "show the config.";
                        return 0;

                    case 3:
                        if (std::string(argv[2]) == "set.color") {
                            std::cout << error << "Introduce un color: gris, verde" << std::endl;
                            return 1;
                        } else {
                            std::cerr << error << "El parámetro indicado no existe. ¿Quisiste decir --help config?" << std::endl;
                            return 1;
                        }

                    case 4:
                        if (std::string(argv[2]) == "set.color") {
                            if (std::string(argv[3]) == "verde") { 
                            std::cout << ANSI_RESET << "El color verde es el nuevo color de terminal.";
                            return 0;
                            } 
                            else if (std::string(argv[3]) == "gris") {
                                std::cout << "El color gris es el nuevo color de terminal.";
                                return 0;
                            } 
                            else {
                                std::cerr << error << "El color indicado no existe. ¿Quisiste decir --help config?" << std::endl;
                                return 1;
                            }
                        }
                        break;

                    default:
                        if (argc >= 4) { //awesome-cli -c set.color red ->red<->>
                            std::cerr << error << "Has indicado más parámetros de los necesarios. ¿Quisiste decir --help config?" << std::endl;
                            return 1;
                        } else { //unhandled error
                            std::cerr << error << "Error inesperado." << std::endl;
                            return 1;
                        }
                    }
                } 
                else if(argv[1] == prefix::long_prefix + "track" || argv[1] == prefix::short_prefix + "t") {
                    switch(argc) {
                         default:
                        if(argc >= 3) {
                            std::cout << warning << "Ignorando cualquier parámetro despues de " << argv[1] << "." << std::endl;
                        }

                        std::cout << ANSI_RESET;

                        case 2:                            
                            std::ifstream cpuinfo("/proc/cpuinfo");
                            cpu.found_cpu = false;

                            while (std::getline(cpuinfo, line8)) {
                                size_t delimiter_pos = line8.find(':');

                                if (line8.find("model name") != std::string::npos) {
                                    if (delimiter_pos != std::string::npos) {
                                        cpu.model_name = line8.substr(delimiter_pos + 2); // Skip ": "	
                                        cpu.found_cpu = true;
                                    }
                                } else if(line8.find("cpu cores") != std::string::npos) { //what is npos 
                                        if(delimiter_pos != std::string::npos) {
                                            cpu.cores = line8.substr(delimiter_pos + 2);
                                        }
                                    }
                            }

                            std::ifstream ram_info("/proc/meminfo");
                            ram.found_ram = false;

                            while(std::getline(ram_info, line9)) {
                            size_t delimiter_pos = line9.find(':');

                            if (line9.find("MemTotal") != std::string::npos) {
                                if (delimiter_pos != std::string::npos) {
                                    ram.found_ram = true;
                                    std::istringstream iss(line9);
                                    std::string memtotal_identifier;
                                    long memtotal_value;

                                    iss >> memtotal_identifier >> memtotal_value;
                                    ram.ram_total_literal = memtotal_value;

                                    if (memtotal_value > 1000000) {
                                        double value_gb = static_cast<double>(memtotal_value) / (1024.0 * 1024.0);
                                        ram.ram_total = value_gb;
                                    } else {
                                        double value_mb = static_cast<double>(memtotal_value) / 1024.0;
                                        ram.ram_total = value_mb;
                                    }
                                }
                            } else if (line9.find("MemFree") != std::string::npos) {
                                if (delimiter_pos != std::string::npos) {
                                    std::istringstream iss(line9);
                                    std::string memfree_identifier;
                                    double memfree_value;

                                    iss >> memfree_identifier >> memfree_value;
                                    double memused_identifier = ram.ram_total_literal - memfree_value;

                                    if (memused_identifier > 1000000) {
                                        double total = static_cast<double>(memused_identifier) / (1024.0 * 1024.0);
                                        ram.ram_used = total;
                                    } else {
                                        double total = static_cast<double>(memused_identifier) / 1024.0;
                                        ram.ram_used = total;
                                    }
                                }
                            } else if (line9.find("MemAvailable") != std::string::npos) {
                                if (delimiter_pos != std::string::npos) {
                                    std::istringstream iss(line9);
                                    std::string memav_identifier;
                                    long memav_value;

                                    iss >> memav_identifier >> memav_value;

                                    double memused_identifier = ram.ram_total_literal - memav_value;
                                    ram.ram_percent = (memused_identifier / ram.ram_total_literal) * 100.0;
                                    //ram.ram_percent = ram_percent;
                                    //if(ram.ram_percent)
                                }
                            }
                        }

                        std::ifstream osname("/etc/os-release");
                        os.found_os = false;

                        //if(osname.is_open()) {
                            while(std::getline(osname, line10)) {
                                size_t pos;
                                while ((pos = line10.find("\"")) != std::string::npos) {
                                    line10.erase(pos, 1);
                                }

                                if(line10.find("PRETTY_NAME") != std::string::npos) {
                                    bool found_os_name = true;
                                    std::string delimiter = "=";
                                    size_t delimiter_pos = line10.find(delimiter);
                                    if (delimiter_pos != std::string::npos) {
                                        std::string os_name = line10.substr(delimiter_pos + delimiter.length());
                                        size_t start_pos = os_name.find_first_not_of(" \"");
                                        size_t end_pos = os_name.find_last_not_of(" \"");
                                        if (start_pos != std::string::npos && end_pos != std::string::npos) {
                                            os_name = os_name.substr(start_pos, end_pos - start_pos + 1);
                                        }

                                os.os_name = os_name;
                            }
                        }
                    }
                        os.found_os = true;

                        gpu.gpu_info = exec("lspci | grep -E 'VGA|3D'");

                        if(cpu.found_cpu) { //is this a good way to check true or is better a cpu.found_cpu
                            info_cpu = "```Modelo: " + cpu.model_name + " || Núcleos: " + cpu.cores + " ```";
                        }

                        if(ram.found_ram)  {
                            std::ostringstream ram_percentStream, ram_usedStream, ram_totalStream;
                            ram_percentStream << std::fixed << std::setprecision(2) << ram.ram_percent;
                            ram_usedStream << std::fixed << std::setprecision(2) << ram.ram_used;
                            ram_totalStream << std::fixed << std::setprecision(2) << ram.ram_total;

                            ram_usage = ram_percentStream.str() + "% [" + ram_usedStream.str() + " / " + ram_totalStream.str() + " GB]"; //should add dynamic memory value
                        }

                        if(os.found_os) {
                            info_os = os.os_model + " || " + os.os_name;
                        }

                        unsigned long long prevIdle = 0;
                        unsigned long long prevTotal = 0;
                        double cpuUsage = calculateCpuUsage(prevIdle, prevTotal);
                        std::ostringstream cpuStream;
                        cpuStream << std::fixed << std::setprecision(2) << cpuUsage;

                        formated_consum = "CPU: " + cpuStream.str();

                        if(cpuUsage < 50) {
                            formated_bot_status = "Eficiente.";
                        } 
                        else if(cpuUsage > 50) {
                            formated_bot_status = "Carga moderada.";
                        } 
                        else if(cpuUsage > 70) {
                            formated_bot_status = "Carga alta.";
                        } 
                        else if(cpuUsage > 90) {
                            formated_bot_status = " Sobrecarga / carga excesiva.";
                        } else {
                            formated_bot_status = " No reconocido.";
                        }
                    
                        disk.disk_usage = exec("df -h /");
                        formated_disk_usage = "```" + disk.disk_usage + "```";

                        network.network_usage = exec("ip -4 addr show $(ip -4 route get 8.8.8.8 | awk '{print $5}')");
                        formated_network_usage = "```" + network.network_usage + "```";

                        return 0;
                    
                    }
                }
                else if(argv[1] == prefix::long_prefix + "stress" || argv[1] == prefix::short_prefix + "c") {
                    switch(argc) {
                     default:
                        if (argc >= 4) {
                            std::cerr << error << "Has indicado más parámetros de los necesarios. ¿Quisiste decir --help <command>?" << std::endl;
                            return 1;
                        }
                        else {
                            std::cerr << error << "Error inesperado." << std::endl;
                            return 1;
                        }

                    case 2:
                        std::cerr << "Uso: " << commands::description::help_stress;
                        std::cerr << error << "           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                        std::cerr << ANSI_RED << "Parámetros insuficientes para " << argv[1] << ". (2 restantes)" << std::endl;
                        return 1;

                    case 3:
                        std::cerr << "Uso: " << commands::description::help_stress;
                        std::cerr << error << "                             ^~~~~~~~~~~~~~~~~~" << std::endl;
                        std::cerr << ANSI_RED << "Parámetros insuficientes para " << argv[1] << ". (1 restante)" << std::endl;
                        return 1;
                    case 4:
                        if(std::string(argv[3]) == "cpu" && std::string(argv[2]) == "loop") { //for loop cpu
                                std::cout << warning << ANSI_RESET << "Estresando procesador con " << ANSI_RED << ANSI_BOLD << NUM_CORES << ANSI_RESET << " núcleos " << ANSI_RED << ANSI_BOLD << "indefinidamente" << ANSI_RESET << ".. (Pulsa CTRL + C para abortar)" << std::endl;
                                std::thread thread[NUM_CORES];  
                            
                                for(int i = 0; i < NUM_CORES; i++) {
                                    thread[i] = std::thread(stress_loop);
                                }

                                for(int i = 0; i < NUM_CORES; i++) {
                                    thread[i].join();
                                }

                                return 0;
                            }
                            else if(std::string(argv[3]) == "cpu") { //for int cpu
                                try {     
                                    contador_top = std::stoi(argv[2]);

                                } catch(const std::invalid_argument&) { //why const
                                    std::cerr << error << "El valor introducido no parece ser un número entero. ¿Quisiste decir --help stress?" << std::endl;
                                    return 1;
                                }

                                integer.is = true;

                                if(contador_top <= 0) {
                                    std::cerr << error << "El valor introducido no parece ser válido, debe estar en el rango de segundos 5 - 1000. ¿Quisiste decir --help stress?" << std::endl;
                                    return 1;
                                }

                                std::cout << warning << ANSI_RESET << "Estresando procesador con " << ANSI_RED << ANSI_BOLD << NUM_CORES << ANSI_RESET << " núcleos durante " << ANSI_RED << ANSI_BOLD << contador_top << ANSI_RESET << " segundos.. (Pulsa CTRL + C para abortar)" << std::endl;
                                std::thread thread[NUM_CORES];  
                            
                                for(int i = 0; i < NUM_CORES; i++) {
                                    thread[i] = std::thread(std::bind(stress_count, contador_top));
                                }

                                for(int i = 0; i < NUM_CORES; i++) {
                                    thread[i].join();
                                }

                                return 0;
                            }    
                        else if(std::string(argv[3]) == "ram" && std::string(argv[2]) == "loop") { //for loop 
                            std::ifstream read_ram("/proc/meminfo");
                            std::string ram_line;
                            std::string kb_ram;

                            while(std::getline(read_ram, ram_line)) {
                                size_t delimiter = ram_line.find(':');

                                if(ram_line.find("MemTotal") != std::string::npos) {
                                    if(delimiter != std::string::npos) {
                                        kb_ram = ram_line.substr(delimiter + 8);
                                    }
                                }
                            }

                            std::cout << warning << ANSI_RESET << "Estresando RAM con una capacidad de " << ANSI_YELLOW << ANSI_BOLD << kb_ram << ANSI_RED << " indefinidamente" << ANSI_RESET << ".. (Pulsa CTRL + C para abortar)" << std::endl;
                            char* memory_array = nullptr;
                            size_t memory_to_alloc = 5 * 1024 * 1024;

                            while(true) {
                                memory_array = (char*)malloc(memory_to_alloc);
                            }
                            return 0;
                        } 
                        else if(std::string(argv[3]) == "ram") {
                                try {     
                                contador_top = std::stoi(argv[2]);

                            } catch(const std::invalid_argument&) { //why const
                                std::cerr << error << "El valor introducido no parece ser un número entero. ¿Quisiste decir --help stress?" << std::endl;
                                return 1;
                            }

                            integer.is = true;

                            if(integer.is) {
                                std::cout << "valid combi" << std::endl;
                                return 0;   
                            } 
                        
                            return 0;
                        } 
                    }
                }
                else if(argv[1] == prefix::long_prefix + "encrypt") {
                    switch(argc) {
                    default:
                        if (argc >= 5) {
                            std::cerr << error << "Has indicado más parámetros de los necesarios. ¿Quisiste decir --help <command>?" << std::endl;
                            return 1;
                        }
                        else {
                            std::cerr << error << "Error inesperado." << std::endl;
                            return 1;
                        }

                    case 2:
                        std::cerr << "Uso: " << commands::description::help_encrypt;
                        std::cerr << error << "            ^~~~~~~~~~~~~~~" << std::endl;
                        std::cerr << ANSI_RED << "Parámetros insuficientes para " << argv[1] << ". (2 restantes)" << std::endl;
                        return 1;

                    case 3:
                        std::cerr << "Uso: " << commands::description::help_encrypt;
                        std::cerr << error << "                    ^~~~~~~" << std::endl;
                        std::cerr << ANSI_RED << "Parámetros insuficientes para " << argv[1] << ". (1 restante)" << std::endl;
                        return 1;
                    case 4:
                        std::string encrypt_key = std::string(argv[3]);
                        std::string encrypt_value = std::string(argv[2]);
                        std::string encrypted = encrypt(encrypt_value, encrypt_key);
                        std::cout << "La cadena encriptada es: " << encrypted << ", con la clave secreta " << encrypt_key << ". Guarda la clave secreta o tu codigo encriptado será inaccesible." << std::endl;
                        return 0;
                    }
                }
                else if(argv[1] == prefix::long_prefix + "decrypt") {
                    switch(argc) {
                    default:
                        if (argc >= 5) {
                            std::cerr << error << "Has indicado más parámetros de los necesarios. ¿Quisiste decir --help <command>?" << std::endl;
                            return 1;
                        }
                        else {
                            std::cerr << error << "Error inesperado." << std::endl;
                            return 1;
                        }

                    case 2:
                        std::cerr << "Uso: " << commands::description::help_decrypt;
                        std::cerr << error << "            ^~~~~~~~~~~~~~~" << std::endl;
                        std::cerr << ANSI_RED << "Parámetros insuficientes para " << argv[1] << ". (2 restantes)" << std::endl;
                        return 1;

                    case 3:
                        std::cerr << "Uso: " << commands::description::help_decrypt;
                        std::cerr << error << "                    ^~~~~~~" << std::endl;
                        std::cerr << ANSI_RED << "Parámetros insuficientes para " << argv[1] << ". (1 restante)" << std::endl;
                        return 1;
                    case 4:
                        std::string encrypted_value = std::string(argv[2]);
                        std::string key = std::string(argv[3]);
                        std::string decrypted = decrypt(encrypted_value, key);
                        std::cout << "La cadena desencriptada es: " << ANSI_ITALIC << decrypted << ANSI_RESET << "." << std::endl;
                        return 0;
                    }
                }
                else if(std::strlen(argv[1]) == 2) {
                    std::cerr << error << "El comando indicado no existe. ¿Quisiste decir -h?" << std::endl;
                    return 1;
                }
                else { //checking if entered a command not registered
                    std::cerr << error << "El comando indicado no existe. ¿Quisiste decir --help?" << std::endl;
                    return 1;
                }
            }
        }

    return 0;
}