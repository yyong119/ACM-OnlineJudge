var
    a:array[1..52,1..52] of longint;
    ch1,ch2:array[1..10000] of char;
    n,i,j,k,x,minnum,min:longint; tmp1,tmp2:char;
function change(ch:char):longint;
begin
    if (ch>='a')and(ch<='z') then exit(ord(ch)-ord('a')+1);
    if (ch>='A')and(ch<='Z') then exit(ord(ch)-ord('A')+27);
end;
begin
    readln(n);
    for i:=1 to 52 do for j:=1 to 52 do a[i,j]:=maxlongint;
    min:=maxlongint;
    for i:=1 to n do
    begin
        readln(ch1[i],tmp1,ch2[i],tmp2,x);
        if (ch1[i]<>ch2[i])and(x<a[change(ch1[i]),change(ch2[i])]) then
        begin
            a[change(ch1[i]),change(ch2[i])]:=x;
            a[change(ch2[i]),change(ch1[i])]:=x;
        end;

    end;
    for k:=1 to 52 do
    for i:=1 to 52 do
    if i<>k then
        for j:=1 to 52 do
            if (k<>j)and(i<>j)and(a[i,k]<>maxlongint)and(a[k,j]<>maxlongint) and(a[i,j]>a[i,k]+a[k,j])
                then a[i,j]:=a[i,k]+a[k,j];
    for i:=27 to 52 do
        if a[i,52]<min then begin minnum:=i-27; min:=a[i,52]; end;
    writeln(chr(minnum+ord('A')),' ',min);
end.