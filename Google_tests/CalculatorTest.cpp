#include "gtest/gtest.h"
#include "../Calculator_lib/Calculator.h"


TEST(Addition, ExampleData){ // 12/2/2020 -> 737761
    Calculator c;

    EXPECT_EQ ("0", c.interpreterForAddition("-0", "-0"));
    EXPECT_EQ ("0", c.interpreterForAddition("0", "-0"));
    EXPECT_EQ ("0", c.interpreterForAddition("-0", "0"));
    EXPECT_EQ ("0", c.interpreterForAddition("0", "0"));

    EXPECT_EQ ("-908050532917446025384098527503", c.interpreterForAddition("-859921394076836515865550948588", "-48129138840609509518547578915"));
    EXPECT_EQ ("-83554071034858134329562364239", c.interpreterForAddition("-78023116652408641629229517744", "-5530954382449492700332846495"));
    EXPECT_EQ ("389263371480074667161509056345", c.interpreterForAddition("803769618109594302287971891823", "-414506246629519635126462835478"));
    EXPECT_EQ ("562498278454670387094322675240", c.interpreterForAddition("466247391819902581298557409999", "96250886634767805795765265241"));
    EXPECT_EQ ("-731441917603648715194873705241", c.interpreterForAddition("-349735270040350326018936247130", "-381706647563298389175937458111"));
    EXPECT_EQ ("-937816224204798320864288422609", c.interpreterForAddition("-594595258390246170501426779134", "-343220965814552150362861643475"));
    EXPECT_EQ ("-86475816611811082694229649498", c.interpreterForAddition("-523775937407701306827231054113", "437300120795890224133001404615"));

    EXPECT_EQ ("13571040", c.interpreterForAddition("4141012", "9430028"));
    EXPECT_EQ ("-7961250", c.interpreterForAddition("-5289943", "-2671307"));
    EXPECT_EQ ("-12271185", c.interpreterForAddition("-3448488", "-8822697"));
    EXPECT_EQ ("10631949", c.interpreterForAddition("8930055", "1701894"));
    EXPECT_EQ ("12134790", c.interpreterForAddition("2350801", "9783989"));
    EXPECT_EQ ("-4313150", c.interpreterForAddition("-6732532", "2419382"));
    EXPECT_EQ ("13947585", c.interpreterForAddition("8992355", "4955230"));
    EXPECT_EQ ("1784470", c.interpreterForAddition("-5070896", "6855366"));
    EXPECT_EQ ("-18092368", c.interpreterForAddition("-9602523", "-8489845"));
    EXPECT_EQ ("-159098", c.interpreterForAddition("-2862185", "2703087"));
    EXPECT_EQ ("-4831992", c.interpreterForAddition("-5434355", "602363"));
    EXPECT_EQ ("-10897608", c.interpreterForAddition("-928185", "-9969423"));
    EXPECT_EQ ("19398918", c.interpreterForAddition("9799371", "9599547"));
    EXPECT_EQ ("579337", c.interpreterForAddition("-1452137", "2031474"));
    EXPECT_EQ ("2995906", c.interpreterForAddition("-462097", "3458003"));
    EXPECT_EQ ("7023624", c.interpreterForAddition("9699667", "-2676043"));
    EXPECT_EQ ("-2479002", c.interpreterForAddition("-2662969", "183967"));
    EXPECT_EQ ("2604076", c.interpreterForAddition("-2311659", "4915735"));
    EXPECT_EQ ("4463153", c.interpreterForAddition("1448223", "3014930"));
    EXPECT_EQ ("-6285981", c.interpreterForAddition("-6553727", "267746"));
    EXPECT_EQ ("-4459909", c.interpreterForAddition("3686206", "-8146115"));
    EXPECT_EQ ("999712", c.interpreterForAddition("-312601", "1312313"));
    EXPECT_EQ ("-136974", c.interpreterForAddition("8553661", "-8690635"));
    EXPECT_EQ ("13618350", c.interpreterForAddition("5537382", "8080968"));
    EXPECT_EQ ("8335711", c.interpreterForAddition("3909049", "4426662"));
    EXPECT_EQ ("6738366", c.interpreterForAddition("-2878377", "9616743"));
    EXPECT_EQ ("-3113216", c.interpreterForAddition("5056250", "-8169466"));
    EXPECT_EQ ("-7123889", c.interpreterForAddition("536621", "-7660510"));
    EXPECT_EQ ("-3166084", c.interpreterForAddition("-218160", "-2947924"));
    EXPECT_EQ ("4814951", c.interpreterForAddition("4244249", "570702"));
    EXPECT_EQ ("-11108954", c.interpreterForAddition("-5715318", "-5393636"));
    EXPECT_EQ ("-2042425", c.interpreterForAddition("-2547730", "505305"));
    EXPECT_EQ ("7569648", c.interpreterForAddition("-1256441", "8826089"));
    EXPECT_EQ ("5163772", c.interpreterForAddition("2125563", "3038209"));
    EXPECT_EQ ("5029032", c.interpreterForAddition("2882085", "2146947"));
    EXPECT_EQ ("-9387140", c.interpreterForAddition("-4079838", "-5307302"));
    EXPECT_EQ ("3757295", c.interpreterForAddition("1598976", "2158319"));
    EXPECT_EQ ("-13797868", c.interpreterForAddition("-5673825", "-8124043"));
    EXPECT_EQ ("-10002072", c.interpreterForAddition("-4935848", "-5066224"));
    EXPECT_EQ ("4961170", c.interpreterForAddition("4299159", "662011"));
    EXPECT_EQ ("-157814", c.interpreterForAddition("-2972370", "2814556"));
    EXPECT_EQ ("-1782188", c.interpreterForAddition("8158455", "-9940643"));
    EXPECT_EQ ("-7390003", c.interpreterForAddition("-9917203", "2527200"));
    EXPECT_EQ ("-907255", c.interpreterForAddition("-8489503", "7582248"));
    EXPECT_EQ ("13446535", c.interpreterForAddition("5460293", "7986242"));
    EXPECT_EQ ("7346524", c.interpreterForAddition("2913717", "4432807"));
    EXPECT_EQ ("3366984", c.interpreterForAddition("8090655", "-4723671"));
    EXPECT_EQ ("-1829530", c.interpreterForAddition("-2773959", "944429"));
    EXPECT_EQ ("-6024545", c.interpreterForAddition("-1909459", "-4115086"));
    EXPECT_EQ ("-7586932", c.interpreterForAddition("-6298711", "-1288221"));
    EXPECT_EQ ("-1241608", c.interpreterForAddition("2764613", "-4006221"));
    EXPECT_EQ ("-8127610", c.interpreterForAddition("-2976122", "-5151488"));
    EXPECT_EQ ("9820556", c.interpreterForAddition("7149919", "2670637"));
    EXPECT_EQ ("-14257334", c.interpreterForAddition("-9149808", "-5107526"));
    EXPECT_EQ ("11080985", c.interpreterForAddition("1668565", "9412420"));
    EXPECT_EQ ("-2300724", c.interpreterForAddition("-9674007", "7373283"));
    EXPECT_EQ ("6872167", c.interpreterForAddition("7901819", "-1029652"));
    EXPECT_EQ ("-11905905", c.interpreterForAddition("-2259481", "-9646424"));
    EXPECT_EQ ("10307269", c.interpreterForAddition("1037460", "9269809"));
    EXPECT_EQ ("-1579134", c.interpreterForAddition("2412236", "-3991370"));
    EXPECT_EQ ("-9838601", c.interpreterForAddition("-6344416", "-3494185"));
    EXPECT_EQ ("3897693", c.interpreterForAddition("-5100473", "8998166"));
    EXPECT_EQ ("3566487", c.interpreterForAddition("7256229", "-3689742"));
    EXPECT_EQ ("9962269", c.interpreterForAddition("9329225", "633044"));
    EXPECT_EQ ("10712835", c.interpreterForAddition("5936482", "4776353"));
    EXPECT_EQ ("177936", c.interpreterForAddition("-4462667", "4640603"));
    EXPECT_EQ ("1525902", c.interpreterForAddition("-5917881", "7443783"));
    EXPECT_EQ ("14413339", c.interpreterForAddition("9763102", "4650237"));
    EXPECT_EQ ("-9744586", c.interpreterForAddition("-232657", "-9511929"));
    EXPECT_EQ ("8626576", c.interpreterForAddition("-902971", "9529547"));
    EXPECT_EQ ("-5639433", c.interpreterForAddition("592190", "-6231623"));
    EXPECT_EQ ("4585492", c.interpreterForAddition("2499772", "2085720"));
    EXPECT_EQ ("15905493", c.interpreterForAddition("8983059", "6922434"));
    EXPECT_EQ ("7435144", c.interpreterForAddition("9385957", "-1950813"));
    EXPECT_EQ ("-2888553", c.interpreterForAddition("-8407225", "5518672"));
    EXPECT_EQ ("-10239097", c.interpreterForAddition("-6077868", "-4161229"));
    EXPECT_EQ ("849068", c.interpreterForAddition("3161815", "-2312747"));
    EXPECT_EQ ("6785548", c.interpreterForAddition("8833165", "-2047617"));
    EXPECT_EQ ("-16323428", c.interpreterForAddition("-6974426", "-9349002"));
    EXPECT_EQ ("11441511", c.interpreterForAddition("1689202", "9752309"));
    EXPECT_EQ ("-6385551", c.interpreterForAddition("-6890553", "505002"));
    EXPECT_EQ ("298385", c.interpreterForAddition("-3212630", "3511015"));
    EXPECT_EQ ("-6813300", c.interpreterForAddition("-5043759", "-1769541"));
    EXPECT_EQ ("5359719", c.interpreterForAddition("7923196", "-2563477"));
    EXPECT_EQ ("-151041", c.interpreterForAddition("5471758", "-5622799"));
    EXPECT_EQ ("-2719007", c.interpreterForAddition("2966834", "-5685841"));
    EXPECT_EQ ("-111734", c.interpreterForAddition("-4046497", "3934763"));
    EXPECT_EQ ("77738", c.interpreterForAddition("3955932", "-3878194"));
    EXPECT_EQ ("5286392", c.interpreterForAddition("4647157", "639235"));
    EXPECT_EQ ("-7182964", c.interpreterForAddition("-8643554", "1460590"));
    EXPECT_EQ ("5285534", c.interpreterForAddition("2097481", "3188053"));
    EXPECT_EQ ("6404535", c.interpreterForAddition("7869141", "-1464606"));
    EXPECT_EQ ("-10199909", c.interpreterForAddition("-5880024", "-4319885"));
    EXPECT_EQ ("781495", c.interpreterForAddition("-840291", "1621786"));
    EXPECT_EQ ("-5467824", c.interpreterForAddition("-7800894", "2333070"));
    EXPECT_EQ ("-7264906", c.interpreterForAddition("2733728", "-9998634"));
    EXPECT_EQ ("-39928", c.interpreterForAddition("7437880", "-7477808"));
    EXPECT_EQ ("4913105", c.interpreterForAddition("7170945", "-2257840"));
    EXPECT_EQ ("53503", c.interpreterForAddition("-3635047", "3688550"));
    EXPECT_EQ ("2676916", c.interpreterForAddition("6095031", "-3418115"));
}

TEST(Substract, ExampleData) {
    Calculator c;

    EXPECT_EQ ("0", c.interpreterForSubstract("-0", "-0"));
    EXPECT_EQ ("0", c.interpreterForSubstract("0", "-0"));
    EXPECT_EQ ("0", c.interpreterForSubstract("-0", "0"));
    EXPECT_EQ ("0", c.interpreterForSubstract("0", "0"));

    EXPECT_EQ ("659111827818097965707300846844", c.interpreterForSubstract("35270632464564687491349336573", "-623841195353533278215951510271"));
    EXPECT_EQ ("262370203660020695516744826601", c.interpreterForSubstract("878076402425962693240217032890", "615706198765941997723472206289"));
    EXPECT_EQ ("-784509206973290070157941624239", c.interpreterForSubstract("-317815437304033363603781724462", "466693769669256706554159899777"));
    EXPECT_EQ ("-1327308614045862023119094601137", c.interpreterForSubstract("-762534970224513176602583946941", "564773643821348846516510654196"));
    EXPECT_EQ ("27817085216110555574869175153", c.interpreterForSubstract("869329669109465946187928289162", "841512583893355390613059114009"));
    EXPECT_EQ ("-10581274610959832906474980772", c.interpreterForSubstract("103959393188021069832231224110", "114540667798980902738706204882"));
    EXPECT_EQ ("-1084002830440293622423747241877", c.interpreterForSubstract("-802234103309959189614902410922", "281768727130334432808844830955"));
    EXPECT_EQ ("751387191010313859175986051947", c.interpreterForSubstract("-240575661182701730290901773328", "-991962852193015589466887825275"));
    EXPECT_EQ ("861909286216228530316027159374", c.interpreterForSubstract("693327915981112853500097234047", "-168581370235115676815929925327"));
    EXPECT_EQ ("-206473724381485263263664533008", c.interpreterForSubstract("-643956319173209210541906404916", "-437482594791723947278241871908"));
}

TEST(Multiplication, ExampleData) {
    Calculator c;

    EXPECT_EQ ("0", c.interpreterForMultiplication("-0", "-0"));
    EXPECT_EQ ("0", c.interpreterForMultiplication("0", "-0"));
    EXPECT_EQ ("0", c.interpreterForMultiplication("-0", "0"));
    EXPECT_EQ ("0", c.interpreterForMultiplication("0", "0"));

    EXPECT_EQ ("198760195987486403290052253132440534897101381318952617048122", c.interpreterForMultiplication("506299974695987535641320706694", "392573979698169620295136165663"));
    EXPECT_EQ ("-4133169011118947333145277544027396312896452365479763109432", c.interpreterForMultiplication("-184763271391679297309630680399", "22370079182875315289454237768"));
    EXPECT_EQ ("804062572621170032123983341408763676321554173780784632678499", c.interpreterForMultiplication("895640595844811078925966823643", "897751370752393964446629107993"));
    EXPECT_EQ ("267067911369097195101829837578891772841776249245045299179680", c.interpreterForMultiplication("631922401921827021944864113940", "422627700105075972647091710472"));
    EXPECT_EQ ("146573970422195875476078739712287138863890314467974143576434", c.interpreterForMultiplication("-531331188473170521278995448238", "-275861785647083473218767176943"));
    EXPECT_EQ ("26956067458230867705059441413484556177029303622151226646496", c.interpreterForMultiplication("-504933774524001348832696243444", "-53385352333862442471924631384"));
    EXPECT_EQ ("-218941507561430735953474315793987973436853114907052359768494", c.interpreterForMultiplication("450477212784267513710905907462", "-486021271105407307602104350237"));
    EXPECT_EQ ("420928163434326883680024835110916661358071264732801979621810", c.interpreterForMultiplication("-804043724064200204957096618415", "-523514021484629082438802501614"));
    EXPECT_EQ ("-150514578035545579916337469790309486885040994410646715001388", c.interpreterForMultiplication("-641792339012689047353653164116", "234522241675698338440636390943"));
    EXPECT_EQ ("-28043678435868111159081929660038894598120771242394363153123", c.interpreterForMultiplication("86494148983942324396910195947", "-324226306233435882542372856809"));
}