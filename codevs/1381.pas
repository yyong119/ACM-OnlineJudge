var
    s:array[1..10] of string[14];
    a:array[1..10] of longint;
    n,i,j,k,t,t1:longint;
    ss:string;
function find(tt:string):longint;
    var
        i:longint;
    begin
        for i:=1 to n do
            if tt=s[i] then exit(i);
        exit(0);
    end;
begin
    readln(n);
    fillchar(a,sizeof(a),0);
    for i:=1 to n do readln(s[i]);
    for i:=1 to n do begin
        readln(ss);
        t:=find(ss);
        readln(t1,j);
        if j>0 then begin
            dec(a[t],(t1 div j)*j);
            t1:=t1 div j;
            for j:=1 to j do begin
                readln(ss);
                t:=find(ss);
                inc(a[t],t1);
            end;
        end;
    end; 
    for i:=1 to n do writeln(s[i],' ',a[i]);
end.