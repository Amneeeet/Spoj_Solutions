class  Refactoring
    {
    public:
    int refactor(int n,int min_factor=2)
        {
        int count=0;
        for(int i=min_factor;i*i<=n;i++)
            {
            ++count;
            count+=refactor(n/i,i);
            }
        return count;
        }
   };
