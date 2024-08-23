// coding: utf-8

/* Name: int bin_search(...)
 * Category: Format (内容編集前提)
 * Arguments: Search value and etc...
 * Return: int, Search result
*/
int bin_search(int value) {
    int l = -1, r = (int)1e8;

    while((r - l) > 1) {
        int m = (l + r) / 2;

        if(...) m = l;
        else m = r;
    }

    return r;
}
