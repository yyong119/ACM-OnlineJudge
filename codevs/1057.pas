var
    save1,save2,i,n,add:longint; p:boolean;
begin
    p:=false;
    for i:=1 to 12 do
    begin
        inc(save1,300);
        readln(n);
        if n>save1 then begin writeln('-',i); p:=true; break; end
        else
        begin
            add:=((save1-n) div 100)*100;
            save1:=save1-add-n;
            save2:=save2+add;
        end;
    end;
    if p=false then writeln(save2+(save2 div 5)+save1);
end.