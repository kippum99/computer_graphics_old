#include <Eigen/Dense>
#include <fstream>
#include <iostream>
#include <string>

using namespace Eigen;
using namespace std;

Matrix4d get_translation_matrix(float tx, float ty, float tz) {
    Matrix4d m = MatrixXd::Identity(4, 4);

    m(0, 3) = tx;
    m(1, 3) = ty;
    m(2, 3) = tz;

    return m;
}

Matrix4d get_rotation_matrix(float rx, float ry, float rz, float angle) {
    Matrix4d m = MatrixXd::Zero(4, 4);

    m(0, 0) = pow(rx, 2) + (1 - pow(rx, 2)) * cos(angle);
    m(0, 1) = rx * ry * (1 - cos(angle)) - rz * sin(angle);
    m(0, 2) = rx * rz * (1 - cos(angle)) - ry * sin(angle);
    m(1, 0) = m(0, 1);
    m(1, 1) = pow(ry, 2) + (1 - pow(ry, 2)) * cos(angle);
    m(1, 2) = ry * rz * (1 - cos(angle)) - rx * sin(angle);
    m(2, 0) = m(0, 2);
    m(2, 1) = m(1, 2);
    m(2, 2) = pow(rz, 2) + (1 - pow(rz, 2)) * cos(angle);
    m(3, 3) = 1;

    return m;
}

Matrix4d get_scaling_matrix(float sx, float sy, float sz) {
    Matrix4d m = MatrixXd::Identity(4, 4);
    m(0, 0) = sx;
    m(1, 1) = sy;
    m(2, 2) = sz;

    return m;
}

int main(int argc, char *argv[]) {
    Matrix4d m = MatrixXd::Identity(4, 4);

    ifstream infile(argv[1]);
    string t;

    while (infile >> t) {
        Matrix4d trans;

        if (t == "t") {
            float tx, ty, tz;
            infile >> tx >> ty >> tz;
            trans = get_translation_matrix(tx, ty, tz);
        }
        else if (t == "r") {
            float rx, ry, rz, angle;
            infile >> rx >> ry >> rz >> angle;
            trans = get_rotation_matrix(rx, ry, rz, angle);
        }
        else if (t == "s") {
            float sx, sy, sz;
            infile >> sx >> sy >> sz;
            trans = get_scaling_matrix(sx, sy, sz);
        }

        m = trans * m;
    }

    // Print out the final transformation matrix
    cout << m.inverse() << endl;
}
