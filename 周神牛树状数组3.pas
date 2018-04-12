program w1082(input,output);
type atype=array[0..200000]of int64  ;
var a,d,f:atype;
    n,x,l,r,m,i,z:int64  ;

function lowbit(k:int64  ):int64  ;
  begin
    exit(k and(-k));
  end;

procedure change(p,x:int64  ; var c:atype);
  begin
    while p<=n do
      begin
        inc(c[p],x);
        inc(p,lowbit(p));
      end;
  end;

function query(k:int64  ;var c:atype):int64  ;
  begin
     query:=0;
     while k>0 do
       begin
         inc(query,c[k]);
         dec(k,lowbit(k));
       end;
  end;

begin
  readln(n);
  for i:=1 to n do
    begin
      read(a[i]);
      d[i]:=a[i]-a[i-1];
    end;
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
    begin
      change(i,d[i],a);
      change(i,i*d[i],f);
    end;

  readln(m);
  for i:=1 to m do
    begin
      read(x);
      if x=1 then
        begin
          read(l,r,z);
          change(l,z,a);
          change(r+1,-z,a);
          change(l,l*z,f);
          change(r+1,-(r+1)*z,f);
        end
      else
        begin
          read(l,r);
          x:=((r+1)*query(r,a)-query(r,f))-(l*query(l-1,a)-query(l-1,f));
          writeln(x);
        end;
    end;
end.
