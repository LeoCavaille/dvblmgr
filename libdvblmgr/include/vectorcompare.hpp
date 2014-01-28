template <class T>
static bool compareVectors(std::vector<T> a, std::vector<T> b) {
  if (a.size() != b.size())
    return false;
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  return (a == b);
}

template <class T> static bool comparePtr(const T &p, const T &q) {
  return *p == *q;
}

template <class T>
static bool compareVectorsPtr(std::vector<T> a, std::vector<T> b) {
  if (a.size() != b.size())
    return false;
  std::sort(a.begin(), a.end(), comparePtr<T>);
  std::sort(b.begin(), b.end(), comparePtr<T>);
  for (unsigned int i = 0; i < a.size(); i++) {
    if (a[i] != b[i])
      return false;
  }
  return true;
}
