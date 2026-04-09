std::string read_file_all_text(const std::string &path) {
    std::ifstream in(path);
    if (!in) return {};
    std::ostringstream ss;
    ss << in.rdbuf();
    return ss.str();
}
std::string encrypt_or_decrypt(std::string raw_text, std::string encryption_key_string, bool encrypt) {
  // do encryption.
  try {
    size_t pos;
    unsigned long long_key = std::stoul(encryption_key_string, &pos, 10);
    char key = (char)(long_key % 256);
    if (encryption_key_string.size() != pos) {
      printf("didnt read key properly\n");
      return {};
    }
    std::string encrypted_text = {};
    
    for ( char c : raw_text ) {
      if (encrypt) encrypted_text.push_back(c+key);
      else encrypted_text.push_back(c-key);
    }
    return encrypted_text;
  } catch (...) {
    printf("stoul exception\n");
    return {};
  }
  printf("Unreachable!!!\n");
  return {};
}
std::string encrypt(std::string raw_text, std::string encryption_key_string) {
  return encrypt_or_decrypt(raw_text, encryption_key_string, true);
}
std::string decrypt(std::string raw_text, std::string encryption_key_string) {
  return encrypt_or_decrypt(raw_text, encryption_key_string, false);
}
