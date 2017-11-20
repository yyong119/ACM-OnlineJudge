var i,j,n,k,m,l:longint;
    a:array [1..10000] of longint;
begin
    readln(m,n); a[1]:=1; l:=1;
    for i:=1 to n do
    begin 
        for j:=1 to l do a[j]:=a[j]*m;
        for j:=1 to l do
          if a[j]>9 then
            begin k:=a[j] div 10; a[j]:=a[j] mod 10; a[j+1]:=a[j+1]+k; end;
        while a[l+1]<>0 do
        begin
            inc(l); 
            if a[l]>9 then
            begin 
                k:=a[l] div 10; 
                a[l]:=a[l] mod 10; 
                a[l+1]:=a[l+1]+k; 
            end;
        end;
    end; 
    for i:=l downto 1 do write(a[i]);
end.