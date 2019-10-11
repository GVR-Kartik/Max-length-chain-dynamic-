struct val{
	int first;
	int second;
};*/
/*You are required to complete this method*/
int max(int a[], int n)
{
    int maxi = INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(a[i]>maxi)
            maxi = a[i];
    }
    return maxi;
}
bool cmp(struct val a, struct val b)
{
    return a.first < b.first;
}
int maxChainLen(struct val p[],int n)
{
//Your code here
    sort(p, p+n, cmp);
    int l[n];
    for (int i=0; i<n; i++)
        l[i] = 1;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(p[i].first > p[j].second && l[i] < l[j] + 1)
            {
                l[i] = l[j] + 1;
            }
        }
    }
    return max(l, n);
}
