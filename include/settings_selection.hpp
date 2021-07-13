#ifndef SETTINGS_H
#define SETTINGS_H

namespace settings_selection
{
    int select_options(int ac, char **av);

    extern int version;
    extern int methods_ID;
    extern int features_ID;
}

#endif // SETTINGS_H