def main():

    in_file = open("particle_branches.txt")
    out_file = open("feats.txt","w")

    lines = in_file.readlines()
    last = lines[-1]

    feats = []
    
    for line in lines:
        feat = line.strip()
        conditions = []
        conditions.append(not "COV_" in feat)
        conditions.append(feat not in feats)
        conditions.append(line is not last)
        
        if (all(conditions)):
            out_file.write("INSERT INTO Base_features (Name, Scope) VALUES \n")
            out_file.write(f'("{line.strip()}","Particle"); \n')
            feats.append(feat)

    out_file.write("INSERT INTO Base_features (Name, Scope) VALUES \n")
    out_file.write(f'("{last.strip()}","Particle");')

if __name__ == "__main__":
    main()
