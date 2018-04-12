program w1082(input,output);
type
  re=record
    l,r:int64;
    m,x:int64;
  end;
var t:array[0..524290] of re;
    a:array[0..200000] of int64;
    i,l,r,x,y,n,q,o:longint;

procedure build(x,l,r:int64);
  var mid:longint;
  begin
    t[x].l:=l;
    t[x].r:=r;
    if l=r then
      begin
        t[x].x:=a[l];
        exit;
      end;

    mid:=(l+r) shr 1;
    build(x shl 1,l,mid);
    build(x shl 1+1,mid+1,r);
    t[x].x:=t[x shl 1].x+t[x shl 1+1].x;
  end;

procedure change(x,l,r,data:int64);
  var mid:longint;
  begin
    if (l=t[x].l)and(r=t[x].r) then
      begin
        inc(t[x].m,data);
        exit;
      end;

    mid:=(t[x].l+t[x].r) shr 1;
    t[x shl 1].m:=t[x].m+t[x shl 1].m;
    t[x shl 1+1].m:=t[x].m+t[x shl 1+1].m;
    t[x].m:=0;

    if l>mid then change(x shl 1+1,l,r,data);
    if r<=mid then change(x shl 1,l,r,data);
    if (l<=mid)and(r>mid) then
       begin
         change(x shl 1,l,mid,data);
         change(x shl 1+1,mid+1,r,data);
       end;

    t[x].x:=t[x shl 1].x+t[x shl 1].m*(t[x shl 1].r-t[x shl 1].l+1)
           +t[x shl 1+1].x+t[x shl 1+1].m*(t[x shl 1+1].r-t[x shl 1+1].l+1);
  end;

function query(x,l,r:int64):int64;
  var mid:longint;
  begin
    if (t[x].l=l)and(t[x].r=r) then exit(t[x].x+t[x].m*(r-l+1));

    mid:=(t[x].l+t[x].r) shr 1;
    t[x shl 1].m:=t[x].m+t[x shl 1].m;
    t[x shl 1+1].m:=t[x].m+t[x shl 1+1].m;
    t[x].x:=t[x].x+t[x].m*(t[x].r-t[x].l+1);
    t[x].m:=0;

    if l>mid then exit(query(x shl 1+1,l,r));
    if r<=mid then exit(query(x shl 1,l,r));
    if (l<=mid)and(r>mid) then
      exit(query(x shl 1,l,mid)+query(x shl 1+1,mid+1,r));
  end;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  build(1,1,n);
  read(q);
  for i:=1 to q do
    begin
      read(o);
      case o of
        1:begin
            read(l,r,x);
            change(1,l,r,x);
          end;
        2:begin
            read(l,r);
            writeln(query(1,l,r));
          end;
      end;
    end;
end.
