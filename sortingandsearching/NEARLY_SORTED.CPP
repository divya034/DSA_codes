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
                                         
Can we use prev ko (mid+n-1)%n and next mid+1%n?  
                                         NO because in prev ques it was compulsory to have a cycle, 
                                         but here if condition goes out of bound, 
                                         we dont need a rotated value, we just need to skip that condition
                                         
                                         we cannot use this, because this is not a rotated array. In case of rotated array,
                                         the next of last element is the first element
                                         and the previous of first element is the last one. But this array is not like a cycle .
                                  
