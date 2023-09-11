using namespace std;

// takes a string of bits and converts it to bytes
vector<char> bits_to_bytes(string bits) {
    vector<char> bytes;
    char byte = 0;

    for (int i = 0; i < ceil(float(bits.size()) / 8); i++) {
        for (int j = 0; j < 8; j++) {
            if (bits[j + (i * 8)] == '1') {
                bitset(byte, j);
            }
        }
        bytes.push_back(byte);
        byte = 0;
    }

    return bytes;
}

// takes bytes and puts its bits in a string
string bytes_to_bits(vector<char> bytes) {
    string bits;

    for (int i = 0; i < bytes.size(); i++) {
        for (int j = 0; j < 8; j++) {
            if (bitcheck(bytes[i], j)) {
                bits.push_back('1');
            } else {
                bits.push_back('0');
            }
        }
    }
    return bits;
}

int main() {

    string bits = ("01110010"); // Byte #1 (8 bits)
    bits.append("11001001"); // Byte #2 (8 bits)
    bits.append("010"); // 3 bits
    vector<char> bytes = bits_to_bytes(bits);
    cout << "\nBYTES:\n";
    for (auto z : bytes) {
        cout << int(z) << ",";
    }
    cout << "\n";
    bits = bytes_to_bits(bytes);
    cout << "\nBITS: ";
    cout << "\n";
    for (auto z : bits) {
        cout << z << ",";
    }
}
