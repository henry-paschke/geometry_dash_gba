#ifndef MAP_H
#define MAP_H

inline int level_size = 200;

inline int level_array[200][5] = {
    {0, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {0, -1, -1, -1, -1},
    {0, 4, -1, -1, -1},
    {0, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {1, -1, -1, -1, -1},
    {3, -1, -1, -1, -1},
    {3, -1, -1, -1, -1},
    {1, 1, -1, -1, -1},
    {3, -1, -1, -1, -1},
    {3, -1, -1, -1, -1},
    {1, 1, 1, -1, -1},
    {0, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {0, -1, -1, -1, -1},
    {0, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {1, -1, -1, -1, -1},
    {3, -1, -1, -1, -1},
    {3, 2, -1, -1, -1},
    {3, 2, -1, -1, -1},
    {3, 2, -1, -1, -1},
    {0, -1, -1, -1, -1},
    {3, -1, -1, -1, -1},
    {0, -1, 4, -1, -1},
    {3, -1, -1, -1, -1},
    {1, 1, -1, -1, -1},
    {3, 2, -1, -1, -1},
    {1, 1, -1, -1, -1},
    {3, -1, -1, -1, -1},
    {3, -1, -1, -1, -1},
    {1, 1, -1, -1, -1},
    {3, 2, -1, -1, -1},
    {3, 2, -1, -1, -1},
    {3, 2, -1, -1, -1},
    {1, 1, -1, -1, -1},
    {3, -1, -1, -1, -1},
    {3, -1, 4, -1, -1},
    {3, -1, -1, -1, -1},
    {1, -1, -1, -1, -1},
    {1, -1, -1, -1, -1},
    {3, -1, -1, -1, -1},
    {1, 1, -1, -1, -1},
    {3, 2, -1, -1, -1},
    {3, 2, -1, -1, -1},
    {3, 2, -1, -1, -1},
    {1, 1, -1, -1, -1},
    {3, -1, -1, -1, -1},
    {1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {1, 1, -1, -1, -1},
    {3, -1, -1, -1, -1},
    {3, -1, -1, -1, -1},
    {1, 1, 1, -1, -1},
    {1, 0, -1, -1, -1},
    {1, 0, -1, 2, -1},
    {1, 0, -1, 2, -1},
    {1, 3, -1, 2, -1},
    {1, 3, -1, 2, -1},
    {0, -1, 2, -1, -1},
    {0, 2, -1, -1, -1},
    {3, 2, -1, -1, -1},
    {2, -1, -1, -1, -1},
    {1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {1, 1, -1, -1, 1},
    {3, 2, -1, -1, 1},
    {3, 2, -1, -1, 1},
    {1, 1, -1, -1, 1},
    {3, -1, -1, -1, -1},
    {1, -1, -1, -1, -1},
    {2, -1, -1, -1, -1},
    {2, -1, -1, -1, -1},
    {2, 0, -1, -1, -1},
    {2, 0, -1, -1, -1},
    {2, -1, -1, -1, -1},
    {1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
};

#endif  // MAP_H
