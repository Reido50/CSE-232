template<typename tmplt_type>
tmplt_type safe_div(tmplt_type num, tmplt_type denom){
    if(denom == 0){
        return 0;
    }else{
        return num/denom;
    }
}