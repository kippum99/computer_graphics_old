#include "object.hpp"

#include <fstream>


Object load_object(string filename) {
    Object obj;
    Vertex null_v{0, 0, 0};
    obj.vertices.push_back(null_v);

    ifstream infile(filename);

    string t;
    while (infile >> t) {
        if (t == "v") {
            double x, y, z;
            infile >> x >> y >> z;
            Vertex v{x, y, z};
            obj.vertices.push_back(v);
        }
        else if (t == "f") {
            int v1, v2, v3;
            infile >> v1 >> v2 >> v3;
            Face f{v1, v2, v3};
            obj.faces.push_back(f);
        }
    }

    return obj;
}
