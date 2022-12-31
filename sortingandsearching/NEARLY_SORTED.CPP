int Nearly_sorted(int a[] , int key ,int n)
{
    int l = 0 , mid;
    int h = n-1;
    while(l<=h)
    {
        mid = l  + (h-l)/2;
        if(key==a[mid]){
        return mid;
        }
        if((mid-1)>=l && a[mid-1] == key)
        {
            return mid-1;
        }
        if((mid+1)<=h && a[mid+1]==key)
        {
            return mid+1;
        }
        if(a[mid]<key)
        {
            l = mid+2;
        }
        else if(a[mid]>key)
        {
            h = mid-2;
        }
    }
}

WHY DOES MID-2 OR MID+2 NOT GIVE SEGMENTATION FAULT?
  
  BECAUSE I NEVER WROTE ARR[MID-2 OR ARR[MID+2,
                                         IF MID+- 2 GOES OUT OF BOUND L<=H WOULD BE FALSE
