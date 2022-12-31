# DSA_codes
This is a repository where I store all the coding questions that I practise. Feel free to refer the same and suggest any changes by starting a pull request :)

1
3 3
1 3 6

bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentNumber = 1, pageSum = 0;
    cout<<"for mid = "<<mid;
    for(int i = 0; i<n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
            cout<<"sum= "<<pageSum<<" ";
        }
        else{
            studentNumber++;
           //|| arr[i] > mid 
            if(studentNumber > m )
                return false;
             pageSum = arr[i];
        }
    }
    cout<<"mid= " << mid<<" "<<"stu= " << studentNumber<<endl;
    if(studentNumber < m)
        return false;
    else{
        return true;
    }
}

int allocateBooks(vector<int> arr, int n, int m) {
    int s = arr[0], sum = 0;
    for(int i = 0; i<n; i++) sum += arr[i];
    int e = sum, ans = -1;
     int mid = s + (e-s)/2;
    while(s<= e){
       
        if(isPossible(arr, n, m, mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    //cout<<sum<<endl;
    
    return ans;
}
for mid = 5sum= 1 sum= 4 mid= 5 stu= 2
for mid = 8sum= 1 sum= 4 mid= 8 stu= 2
for mid = 9sum= 1 sum= 4 mid= 9 stu= 2
for mid = 10sum= 1 sum= 4 sum= 10 mid= 10 stu= 1






bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentNumber = 1, pageSum = 0;
    cout<<"for mid = "<<mid<<" ";
    for(int i = 0; i<n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
            cout<<"sum= "<<pageSum<<" ";
        }
        else{
            studentNumber++;
            cout<<"stu= "<<studentNumber;cout<<"\n";
           //|| arr[i] > mid 
            if(studentNumber > m || arr[i] > mid )
                return false;
             pageSum = arr[i];
        }
        
    }
    //cout<<"mid= " << mid<<" "<<"stu= " << studentNumber<<endl;
    
        return true;
    
}

int allocateBooks(vector<int> arr, int n, int m) {
    int s = arr[0], sum = 0;
    for(int i = 0; i<n; i++) sum += arr[i];
    int e = sum, ans = -1;
     int mid = s + (e-s)/2;
    while(s<= e){
       
        if(isPossible(arr, n, m, mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    //cout<<sum<<endl;
    
    return ans;
}

for mid = 5 sum= 1 sum= 4 stu= 2
for mid = 8 sum= 1 sum= 4 stu= 2
for mid = 6 sum= 1 sum= 4 stu= 2
