import pytmx

tmxdata = pytmx.TiledMap("map/map.tmx")

rows = []
for i in range(tmxdata.width):
    row = []
    for j in range(5):
        if (tmxdata.get_tile_image(i, j, 0)):
            row.append(tmxdata.get_tile_properties(i, j, 0)["id"])
        else:
            row.append(-1)
    rows.append(row[::-1])

def create_header_from_list(lst, filename, guard_name):
    rows = len(lst)
    cols = len(lst[0])

    header = f"#ifndef {guard_name}\n"
    header += f"#define {guard_name}\n\n"
    header += f"inline int level_size = {rows};\n\n"
    header += f"inline int level_array[{rows}][{cols}] = {{\n"
    
    for row in lst:
        row_str = "{" + ", ".join(str(item) for item in row) + "}"
        header += "    " + row_str + ",\n"
    
    header += "};\n\n"
    header += f"#endif  // {guard_name}\n"

    with open(filename, "w") as file:
        file.write(header)

create_header_from_list(rows, "include/map.h", "MAP_H")