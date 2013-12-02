template <class T>
static bool compareVectors(vector<T> a, vector<T> b)
{
    if ( a.size() != b.size() )
        return false;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    return (a == b);
}
