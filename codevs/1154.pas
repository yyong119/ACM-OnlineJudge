const    maxn=100; 
var     
    c:array[0..maxn] of longint;     
    a:array[0..maxn,0..maxn] of longint;    
    n,i,j,k,t,v,u,max:longint; 
begin        
    readln(n);     
    for i:=0 to n-1 do read(c[i]);    fillchar(a,sizeof(a),0);    
    for i:=2 to n do 
    begin        
        for j:=0 to n-1 do 
        begin          
            k:=(j+i) mod n;          
            max:=0;           
            for v:=j+1 to j+i-1 do 
            begin             
                u:=v mod n;              
                t:=c[j]*c[u]*c[k]+a[j,u]+a[u,k];             
                if t>max then max:=t;             
            end;           
            a[j,k]:=max;          
        end;       
    end;    
    max:=0;     
    for i:=0 to n-1 do 
        if a[i,i]>max then max:=a[i,i];    
    writeln(max);     
end. 