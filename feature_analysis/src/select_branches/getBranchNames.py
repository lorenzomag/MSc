load_global_features = True
load_particle_features = True


def main():

    global load_global_features
    global load_particle_features

    source_file = open("../select_features.C")
    if load_global_features:
        global_branch_file = open("global_branches.txt")
    if load_particle_features:
        particle_branch_file = open("particle_branches.txt")
    f_out = open("new_select_features.cpp", "w")

    is_global_features = False
    global_features_printed = False
    is_particle_features = False
    particle_features_printed = False

    unique_global_features = []
    unique_particle_features = []


    for line in source_file:

        if load_global_features:
            if "// BEGIN LIST OF GLOBAL FEATURES\n" in line : 
                is_global_features = True
                f_out.write("// BEGIN LIST OF GLOBAL FEATURES\n")
                continue
            if "// END LIST OF GLOBAL FEATURES\n" in line : 
                is_global_features = False
                f_out.write("// END LIST OF GLOBAL FEATURES\n")
                continue
        if load_particle_features:
            if "// BEGIN LIST OF PARTICLE FEATURES\n" in line : 
                is_particle_features = True
                f_out.write("// BEGIN LIST OF PARTICLE FEATURES\n")
                continue
            if "// END LIST OF PARTICLE FEATURES\n" in line : 
                is_particle_features = False
                f_out.write("// END LIST OF PARTICLE FEATURES\n")
                continue
        
        if is_global_features and load_global_features:
            if not global_features_printed:
                for in_line in global_branch_file:
                    in_line = in_line.rstrip("\n")
                    if in_line not in unique_global_features:
                        f_out.write(f"\t\t\t{{\"{in_line}\", false}},\n")
                        unique_global_features.append(in_line)
                global_features_printed = True

        elif is_particle_features and load_particle_features:
            if not particle_features_printed:
                for in_line in particle_branch_file:
                    in_line = in_line.rstrip("\n")
                    if in_line not in unique_particle_features:
                        f_out.write(f"\t\t\t{{\"{in_line}\", false}},\n")
                        unique_particle_features.append(in_line)
                particle_features_printed = True
        else:
            f_out.write(line)


if __name__ == "__main__":
    main()
