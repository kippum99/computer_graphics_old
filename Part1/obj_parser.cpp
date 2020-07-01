#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct Vertex {
    float x;
    float y;
    float z;
};

struct Face {
    int v1;
    int v2;
    int v3;
};

struct Object {
    vector<Vertex> vertices;
    vector<Face> faces;
};


int main(int argc, char *argv[]) {
    vector<Object> objects;
    Vertex null_v{0, 0, 0};

    // Store file contnet into data structures
    for (int i = 1; i < argc; i++) {
        Object obj;
        obj.vertices.push_back(null_v);

        ifstream infile(argv[i]);

        string t;
        while (infile >> t) {
            if (t == "v") {
                float x, y, z;
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

        objects.push_back(obj);
    }

    // Output from data structures
    for (int i = 0; i < (int) objects.size(); i++) {
        cout << "obj_file" << i + 1 << ":" << endl;

        for (Vertex v : objects[i].vertices) {
            cout << "v " << v.x << " " << v.y << " " << v.z << endl;
        }

        for (Face f : objects[i].faces) {
            cout << "f " << f.v1 << " " << f.v2 << " " << f.v3 << endl;
        }
    }
}
