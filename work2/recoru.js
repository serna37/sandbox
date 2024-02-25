javascript: (async () => {
    const $$ = document;
    const $ = v => v.startsWith('#') ? $$.getElementById(v.slice(1)) : $$.querySelector(v);
    const _$ = (e = "div") => $$.createElement(e);
    const attr = (e, att) => Object.entries(att).map(([k, v]) => e[k] = v);
    const css = (e, sty) => Object.entries(sty).map(([k, v]) => e.style[k] = v);
    const event = (e, f, v = 'click') => e.addEventListener(v, f);
    const sleep = (ms) => new Promise(r => setTimeout(r, ms));
    const now = new Date().toISOString().split("T")[0].replaceAll("-", "");
    /** OPEN */
    const url = "https://app.recoru.in/ap/home/";
    if (window.location.href !== url) window.location.href = url;
    /** REGIST BREAK TIME */
    loadBreaktimeEditDialog('769', now, '1');
    while (!$("#breaktimeEditDialogForm")) await sleep(500);
    $("#breaktimeDtos[0].breaktimeStart").value = '12:00';
    $("#breaktimeDtos[0].breaktimeEnd").value = '13:00';
    setAttendanceChangeFlagForDialog("BEDC");
    updateBreaktimeEditDialog();
    /** REGIST WORK TIME */
    loadAttendanceEditDialog('769', now, '1', 'false');
    while (!$("#attendanceEditDialogForm")) await sleep(500);
    const prefix = "#chartDto.attendanceDtos[0].";
    $(`${prefix}attendId`).value = 34;
    $(`${prefix}worktimeStart`).value = "10:00";
    $(`${prefix}worktimeEnd`).value = "19:00";
    $(`${prefix}attendIdChanged`).value = "true";
    $(`${prefix}worktimeStartChanged`).value = "true";
    $(`${prefix}worktimeEndChanged`).value = "true";
    setAttendanceChangeFlagForDialog("AEDC");
    updateAttendanceEditDialog();
})();
