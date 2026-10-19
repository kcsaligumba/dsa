class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for (string& s : strs) {
            encoded_string += to_string(s.length()) + "#" + s;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_string;
        int i = 0;
        while (i < s.length()) {
            string str_size;
            while (s[i] != '#') {
                str_size += s[i];
                i++;
            }
            i++;

            int num_size = stoi(str_size);
            string str;
            for (int j = i; j < i + num_size; j++) {
                str += s[j];
            }

            decoded_string.push_back(str);
            i += num_size;
        }
        return decoded_string;
    }
};
