const
    a:array[1..6] of integer=(100,50,20,10,5,1);
var
    n,c,p,i,j:longint; pp:boolean;
begin
    readln(n,c);
    writeln(n-c); p:=n-c;
    for i:=1 to 6 do
    begin
        j:=0;
        repeat
            inc(j);
        until p-j*a[i]<0;
        if j>1 then 
        begin 
            if pp=true then write('+'); 
            write(a[i],'*',j-1); 
            dec(p,a[i]*(j-1)); 
            pp:=true; 
        end;
    end;
    writeln('=',n-c);
end.