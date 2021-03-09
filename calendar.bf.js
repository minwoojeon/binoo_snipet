
/* license by botbinoo */

function convertNo2Day(no)
{
    return (["일","월","화","수","목","금","토"])[no];
}
function convertCalendarComp2Weeks(calcp)
{
    var weekComp = [];
    weekComp.length = 42;
    var targetPt = 0;
    
    for(var inx=0; inx<weekComp.length; inx++)
    {
        weekPt = inx%7;
        if(targetPt < calcp.data.length && calcp.data[targetPt].day == weekPt)
        {
            weekComp[inx] = { date : calcp.data[targetPt].date, day : calcp.data[targetPt].day, dayCaption : calcp.data[targetPt].dayCaption, isEmpty : false };
            targetPt++;
        }else{
            weekComp[inx] = { date : "", day : weekPt, dayCaption : convertNo2Day(weekPt), isEmpty : true }
        }
        weekPt++;
    }
    calcp.data = weekComp;
    return calcp;
}
function getCalendarComp(year, month)
{
    var tmpDate = new Date(year, month, 1);
    tmpDate.setDate(tmpDate.getDate()-1);
    var lastDate = tmpDate.getDate();
    var tmpCals = {
        month : month
        , data : []
    };
    tmpCals.data.length = lastDate;
    var weekPt = tmpDate.getDay();

    for(var inx=0; inx<lastDate; inx++)
    {
        if(weekPt < 0) weekPt = 6;
        tmpCals.data[lastDate-inx-1] = { date : lastDate-inx, day : weekPt, dayCaption : convertNo2Day(weekPt) };
        weekPt--;
    }
    return tmpCals;
}

var calendarSrc = convertCalendarComp2Weeks(getCalendarComp(2021, 3));

