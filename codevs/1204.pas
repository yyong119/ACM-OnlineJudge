var
    a,b:string; c:char; p:boolean;
    i,j,k,la,lb:longint;
begin
    read(c);
    repeat
        a:=a+c;
        read(c);
    until c=' ';
    while c=' ' do read(c);
    b:=b+c;
    while (c>='a')and(c<='z') or (c>='A')and(c<='Z')  do
    begin
        read(c);
        b:=b+c;
    end; la:=length(a); lb:=length(b)-1;
    for i:=1 to la do
        if a[i]=b[1] then
        begin
            p:=true;
            for j:=2 to lb do
                if a[i+j-1]<>b[j] then begin p:=false; break; end;
            if p=true then
            begin
                writeln(i);
                break;
            end;
        end;
end.