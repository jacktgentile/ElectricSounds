//
//  Test_Signals.cpp
//  GistTest
//
//  Created by Adam Stark on 30/12/2013.
//  Copyright (c) 2013 Adam Stark. All rights reserved.
//

#include "Test_Signals.h"

float pitchTest1_result = 370.151285694;

float pitchTest1[512] = {-0.08837890625, -0.108825683594, -0.113555908203, -0.113891601562, -0.131011962891, -0.122619628906, -0.103607177734, -0.115112304688, -0.12646484375, -0.131225585938, -0.13037109375, -0.134307861328, -0.139801025391, -0.147247314453, -0.138336181641, -0.137115478516, -0.159332275391, -0.132385253906, -0.0874633789062, -0.07421875, -0.0622253417969, -0.0286560058594, 0.0151672363281, 0.0459289550781, 0.0648498535156, 0.0706481933594, 0.0870971679688, 0.0884094238281, 0.0824584960938, 0.0968322753906, 0.101806640625, 0.0877380371094, 0.0843811035156, 0.113159179688, 0.127319335938, 0.150207519531, 0.166198730469, 0.153717041016, 0.163543701172, 0.173950195312, 0.171081542969, 0.169281005859, 0.183898925781, 0.165161132812, 0.164031982422, 0.188232421875, 0.172271728516, 0.162994384766, 0.163940429688, 0.146911621094, 0.135864257812, 0.141845703125, 0.124176025391, 0.0873413085938, 0.0607299804688, 0.0252685546875, 0.0136108398438, -0.00726318359375, -0.0510559082031, -0.0594177246094, -0.0481872558594, -0.053955078125, -0.0607299804688, -0.0379333496094, -0.0280456542969, -0.0200805664062, -0.0148620605469, -0.0172119140625, -0.00613403320312, -0.0029296875, -0.0228881835938, -0.0308532714844, -0.00494384765625, -0.00738525390625, -0.0117797851562, 0.007568359375, 0.0180053710938, 0.0216674804688, 0.0205688476562, 0.0241394042969, 0.0425720214844, 0.0473937988281, 0.0350646972656, 0.0364990234375, 0.0548095703125, 0.0528564453125, 0.045654296875, 0.0477294921875, 0.0486755371094, 0.0520935058594, 0.0545959472656, 0.0550231933594, 0.0729370117188, 0.0925903320312, 0.0837097167969, 0.0855102539062, 0.0934448242188, 0.0745544433594, 0.0517883300781, 0.0399780273438, 0.0260009765625, 0.0179748535156, 0.0145874023438, 0.0067138671875, 0.0141296386719, 0.0258483886719, 0.01171875, -0.0008544921875, -0.008544921875, -0.0197448730469, -0.0195007324219, -0.0247802734375, -0.0370788574219, -0.0503540039062, -0.0709838867188, -0.0917358398438, -0.0950317382812, -0.0997009277344, -0.118133544922, -0.136657714844, -0.147796630859, -0.149932861328, -0.161376953125, -0.159698486328, -0.162384033203, -0.164367675781, -0.160766601562, -0.164367675781, -0.165771484375, -0.16552734375, -0.171112060547, -0.182861328125, -0.177886962891, -0.17041015625, -0.170379638672, -0.181121826172, -0.179168701172, -0.160949707031, -0.150024414062, -0.144653320312, -0.1103515625, -0.0611877441406, -0.0303649902344, 0.0015869140625, 0.0119323730469, 0.0113220214844, 0.0285034179688, 0.0215759277344, 0.000885009765625, -0.00506591796875, -0.0069580078125, -0.00650024414062, 0.0126647949219, 0.0370788574219, 0.0680236816406, 0.0926818847656, 0.0803833007812, 0.0812377929688, 0.101013183594, 0.113494873047, 0.104400634766, 0.0886535644531, 0.0883178710938, 0.102294921875, 0.114288330078, 0.100463867188, 0.101348876953, 0.115661621094, 0.103881835938, 0.0776672363281, 0.0743103027344, 0.0638427734375, 0.0328063964844, 0.0006103515625, -0.0322265625, -0.0331115722656, -0.0279235839844, -0.0433654785156, -0.06787109375, -0.0767822265625, -0.0869445800781, -0.0920715332031, -0.0834350585938, -0.0646667480469, -0.0394897460938, -0.0414733886719, -0.0508117675781, -0.0360412597656, -0.019287109375, -0.0340270996094, -0.0367431640625, -0.0254211425781, -0.0172729492188, -0.0171508789062, -0.0199890136719, -0.025634765625, -0.0202026367188, -0.0189819335938, -0.0232849121094, -0.00912475585938, 0.00930786132812, 0.00997924804688, -0.0157775878906, -0.022705078125, -0.0178833007812, -0.0157165527344, -0.0115661621094, -0.0057373046875, -0.00482177734375, -0.001220703125, -0.00839233398438, -0.016845703125, -0.00369262695312, 0.00607299804688, 0.00637817382812, -0.00271606445312, -0.00857543945312, -0.0163269042969, -0.0308532714844, -0.0427856445312, -0.0490112304688, -0.052978515625, -0.0613098144531, -0.0733947753906, -0.0817260742188, -0.0863342285156, -0.0852966308594, -0.0892028808594, -0.0968017578125, -0.0986938476562, -0.0984497070312, -0.107391357422, -0.123504638672, -0.133483886719, -0.142913818359, -0.151916503906, -0.158325195312, -0.157928466797, -0.173187255859, -0.197418212891, -0.217742919922, -0.221588134766, -0.199951171875, -0.202606201172, -0.223846435547, -0.230224609375, -0.22998046875, -0.237091064453, -0.243072509766, -0.246551513672, -0.249755859375, -0.250915527344, -0.261077880859, -0.263488769531, -0.262634277344, -0.235900878906, -0.210845947266, -0.194610595703, -0.160827636719, -0.129974365234, -0.0787353515625, -0.0345458984375, -0.0202941894531, 0.00265502929688, 0.0289611816406, 0.0350341796875, 0.0309143066406, 0.0416564941406, 0.0343627929688, -0.00125122070312, -0.0281372070312, -0.0128784179688, 0.0292053222656, 0.0727844238281, 0.0809631347656, 0.0879211425781, 0.119750976562, 0.126617431641, 0.132171630859, 0.135223388672, 0.125213623047, 0.110473632812, 0.105377197266, 0.111022949219, 0.118713378906, 0.125640869141, 0.105041503906, 0.0776977539062, 0.0771789550781, 0.0889587402344, 0.0780639648438, 0.0492553710938, 0.0165100097656, -0.00830078125, -0.0267639160156, -0.0428466796875, -0.0618591308594, -0.0705261230469, -0.0742492675781, -0.0869445800781, -0.0794372558594, -0.0644226074219, -0.0534057617188, -0.0657348632812, -0.07763671875, -0.0674438476562, -0.0528869628906, -0.0630187988281, -0.0787353515625, -0.0746765136719, -0.0656127929688, -0.0744323730469, -0.0828857421875, -0.0796813964844, -0.0729064941406, -0.0626831054688, -0.0572204589844, -0.0542297363281, -0.0500793457031, -0.0538330078125, -0.0707092285156, -0.06591796875, -0.0497436523438, -0.0439453125, -0.0482177734375, -0.0503845214844, -0.0453491210938, -0.0280456542969, -0.0308837890625, -0.0372009277344, -0.0281066894531, -0.0243530273438, -0.0152587890625, -0.00323486328125, 0.00299072265625, 0.008544921875, 0.00234985351562, -0.0119934082031, -0.0200805664062, -0.0272827148438, -0.0384216308594, -0.0591430664062, -0.0650329589844, -0.0552978515625, -0.0558166503906, -0.0648498535156, -0.0704956054688, -0.0752258300781, -0.0810241699219, -0.0805053710938, -0.0791931152344, -0.0787353515625, -0.0863342285156, -0.106109619141, -0.12060546875, -0.114624023438, -0.119476318359, -0.136413574219, -0.13671875, -0.136596679688, -0.126586914062, -0.113128662109, -0.111785888672, -0.107849121094, -0.104736328125, -0.101715087891, -0.0862426757812, -0.0914306640625, -0.110870361328, -0.111541748047, -0.100799560547, -0.109893798828, -0.115325927734, -0.113922119141, -0.109222412109, -0.08447265625, -0.0724792480469, -0.0710754394531, -0.0497131347656, -0.00881958007812, 0.0235290527344, 0.04931640625, 0.0587463378906, 0.0556945800781, 0.0617370605469, 0.0672607421875, 0.0596923828125, 0.0618286132812, 0.0710754394531, 0.0666809082031, 0.0662231445312, 0.0899963378906, 0.112945556641, 0.129333496094, 0.148742675781, 0.148376464844, 0.149597167969, 0.162170410156, 0.154449462891, 0.14404296875, 0.149230957031, 0.132629394531, 0.125030517578, 0.133087158203, 0.118560791016, 0.109222412109, 0.0948181152344, 0.0745544433594, 0.0837707519531, 0.109069824219, 0.0931701660156, 0.0646057128906, 0.0498962402344, 0.0244445800781, 0.00326538085938, -0.0186767578125, -0.0494079589844, -0.0506286621094, -0.0494384765625, -0.0705871582031, -0.0650939941406, -0.0423889160156, -0.0362854003906, -0.0255126953125, -0.0072021484375, 0.00833129882812, 0.0261840820312, 0.0323181152344, 0.0267639160156, 0.0318603515625, 0.0505065917969, 0.052978515625, 0.0645446777344, 0.0796813964844, 0.0804443359375, 0.082763671875, 0.0897827148438, 0.09326171875, 0.106079101562, 0.115295410156, 0.101684570312, 0.108489990234, 0.119750976562, 0.0978393554688, 0.0862731933594, 0.101654052734, 0.112762451172, 0.124298095703, 0.124603271484, 0.105133056641, 0.101257324219, 0.109680175781, 0.0978698730469, 0.085693359375, 0.0841064453125, 0.0728454589844, 0.0614318847656, 0.0466918945312, 0.030517578125, 0.0242309570312, 0.0171813964844, -0.00350952148438, -0.0114135742188, -0.00335693359375, -0.00390625, -0.001708984375, -0.00296020507812, -0.00286865234375, 0.00885009765625, -0.00384521484375, -0.0259094238281, -0.0248718261719, -0.0406188964844, -0.0730285644531, -0.0839538574219, -0.0840454101562, -0.100311279297, -0.116058349609, -0.127014160156, -0.129486083984, -0.126281738281, -0.137939453125, -0.152587890625, -0.14111328125, -0.142761230469, -0.177185058594, -0.177032470703, -0.183837890625, -0.192749023438, -0.182434082031, -0.193756103516, -0.209381103516, -0.206390380859, -0.190368652344, -0.162536621094, -0.125213623047, -0.114471435547, -0.0984497070312, -0.0425109863281, 0.000335693359375, 0.0287170410156, 0.0409240722656, 0.0396118164062, 0.0419006347656, 0.0487365722656, 0.0514526367188, 0.0414123535156, 0.0355834960938, 0.0343017578125, 0.0425720214844, 0.0729675292969, 0.111938476562};


float pitchTest2_result = 438.251149448;

float pitchTest2[512] = {0.0, 0.0623979284019, 0.124552673438, 0.186221999502, 0.247165562809, 0.307145848088, 0.365929094252, 0.423286205431, 0.478993643831, 0.532834300924, 0.584598343587, 0.634084031883, 0.681098505305, 0.725458534405, 0.7669912349, 0.805534741449, 0.840938838496, 0.873065545698, 0.90178965568, 0.926999222007, 0.948595995469, 0.966495806987, 0.980628895651, 0.990940180591, 0.99738947565, 0.999951645999, 0.998616706096, 0.993389858598, 0.984291474093, 0.971357011703, 0.95463688089, 0.934196245, 0.910114767295, 0.882486300488, 0.851418520967, 0.817032509148, 0.779462277591, 0.73885424871, 0.695366684124, 0.649169067862, 0.600441445833, 0.549373724136, 0.496164928937, 0.441022430804, 0.384161136522, 0.325802651542, 0.266174416311, 0.205508819871, 0.144042294175, 0.0820143926326, 0.019666856504, -0.0427573272389, -0.105014872906, -0.166863144245, -0.228061100068, -0.288370233662, -0.347555502318, -0.405386243366, -0.461637073133, -0.516088765333, -0.568529105458, -0.618753717838, -0.666566862155, -0.711782196305, -0.754223502624, -0.793725374665, -0.830133861832, -0.863307069376, -0.893115711399, -0.919443614717, -0.942188171628, -0.9612607398, -0.976586987738, -0.988107184474, -0.995776432362, -0.999564842051, -0.999457648978, -0.995455270905, -0.987573306296, -0.975842473522, -0.960308491141, -0.941031899722, -0.918087825901, -0.891565689587, -0.861568855467, -0.828214230165, -0.791631806617, -0.751964157455, -0.709365879358, -0.664002990539, -0.616052283727, -0.565700637148, -0.513144286209, -0.45858805871, -0.402244576563, -0.344333427151, -0.285080307519, -0.224716144774, -0.16347619609, -0.101599131838, -0.0393261054224, 0.0231001865733, 0.0854364502418, 0.147439742544, 0.208868418128, 0.269483071097, 0.329047468043, 0.387329468718, 0.444101930758, 0.499143594918, 0.552239947393, 0.603184055838, 0.651777375843, 0.697830524728, 0.741164019613, 0.781608976926, 0.819007770586, 0.853214646325, 0.884096289728, 0.911532345809, 0.93541588806, 0.955653835184, 0.972167313855, 0.984891966115, 0.993778200192, 0.998791383779, 0.999911979001, 0.997135618564, 0.990473122774, 0.979950457367, 0.965608632313, 0.947503541989, 0.925705747339, 0.900300200881, 0.871385915618, 0.839075579155, 0.803495114527, 0.76478318943, 0.723090675801, 0.678580061819, 0.631424818642, 0.581808724338, 0.529925147647, 0.475976294366, 0.42017241929, 0.362731006789, 0.303875923206, 0.243836544381, 0.182846861708, 0.121144570199, 0.0589701421124, -0.00343411023212, -0.0658249788233, -0.12795930781, -0.189594941152, -0.250491666376, -0.310412150754, -0.369122866258, -0.426394999695, -0.482005344453, -0.535737170407, -0.587381068581, -0.636735767278, -0.683608916496, -0.727817837569, -0.769190235128, -0.807564868582, -0.84279218052, -0.874734879586, -0.903268475541, -0.928281764437, -0.949677262016, -0.967371583634, -0.981295769233, -0.991395552104, -0.997631570375, -0.99997952042, -0.998430251578, -0.99298980181, -0.983679374176, -0.970535254193, -0.953608668422, -0.932965584825, -0.908686455663, -0.880865903957, -0.849612354705, -0.815047612325, -0.777306385943, -0.73653576439, -0.692894642959, -0.646553104134, -0.597691754734, -0.546501022034, -0.49318041161, -0.437937729807, -0.380988273858, -0.322553992803, -0.26286262249, -0.202146798019, -0.140643147095, -0.0785913678156, -0.0162332945006, 0.046188044812, 0.108429375517, 0.170248124558, 0.231403365804, 0.291656759012, 0.350773478712, 0.408523129388, 0.464680643402, 0.519027158147, 0.571350869021, 0.621447854895, 0.669122872849, 0.714190119099, 0.756473953124, 0.795809582193, 0.832043703609, 0.865035102177, 0.894655200564, 0.920788560399, 0.94333333217, 0.96220165217, 0.977319984919, 0.988629409757, 0.996085850479, 0.999660247108, 0.999338669153, 0.995122369898, 0.987027781521, 0.975086451051, 0.959344917421, 0.939864530087, 0.91672120994, 0.89000515341, 0.85982048095, 0.826284831244, 0.789528902737, 0.749695944262, 0.706941196755, 0.661431288238, 0.61334358442, 0.562865497446, 0.510193755499, 0.45553363609, 0.399098166031, 0.341107291208, 0.281787019381, 0.221368539369, 0.160087320036, 0.0981821925975, 0.0358944198274, -0.0265332442186, -0.0888575002862, -0.150835452133, -0.212225553168, -0.27278854783, -0.332288404038, -0.39049323308, -0.447176193352, -0.502116374424, -0.555099658002, -0.605919552403, -0.654377997318, -0.700286135713, -0.743465049859, -0.78374645863, -0.820973373344, -0.855000709596, -0.88569585269, -0.912939174487, -0.936624499623, -0.956659519311, -0.972966151095, -0.98548084316, -0.994154822013, -0.998954282568, -0.999860519893, -0.99687000211, -0.989994384161, -0.979260462382, -0.964710070073, -0.94639991446, -0.924401355687, -0.898800128709, -0.869696009155, -0.837202424473, -0.801446011867, -0.762566124759, -0.720714289682, -0.676053615738, -0.628758158914, -0.579012243733, -0.527009744885, -0.472953331643, -0.417053677994, -0.359528641586, -0.30060241467, -0.240504650353, -0.179469567575, -0.117735038283, -0.0555416603794, 0.00686817996527, 0.0692512529611, 0.131364433138, 0.192965646881, 0.253814815858, 0.313674792683, 0.372312285144, 0.42949876542, 0.485011360714, 0.538633721862, 0.590156866503, 0.639379993554, 0.686111265785, 0.73016855747, 0.771380164183, 0.809585471982, 0.844635583372, 0.876393897597, 0.904736643022, 0.929553359502, 0.950747328879, 0.968235951924, 0.981951070249, 0.991839231942, 0.997861899882, 0.999995601934, 0.998232022424, 0.992578034547, 0.983055673583, 0.969702051018, 0.952569209906, 0.931723922049, 0.907247427758, 0.879235119243, 0.847796168839, 0.813053103525, 0.775141327405, 0.734208593995, 0.690414430384, 0.643929515509, 0.594935014968, 0.543621874965, 0.490190078133, 0.434847864146, 0.377810918142, 0.319301530136, 0.259547728691, 0.19878239222, 0.137242341389, 0.075167416159, 0.0127995410556, -0.0496182176825, -0.111842599405, -0.17363109711, -0.234742902566, -0.294939844812, -0.353987318383, -0.411655197637, -0.467718733623, -0.521959429996, -0.574165894558, -0.624134663125, -0.671670992478, -0.716589619344, -0.758715482415, -0.79788440462, -0.83394373297, -0.866752933492, -0.896184138929, -0.922122647084, -0.944467367843, -0.963131217153, -0.97804145642, -0.989139975988, -0.99638352161, -0.999743863025, -0.999207903979, -0.994777733265, -0.986470616581, -0.974318929242, -0.958370030004, -0.938686076491, -0.91534378295, -0.88843412127, -0.858061966442, -0.824345687824, -0.787416687827, -0.747418889793, -0.704508177089, -0.65885178558, -0.610627651862, -0.560023719788, -0.507237207998, -0.452473841294, -0.395947048875, -0.337877132537, -0.278490408088, -0.218018323332, -0.156696556048, -0.0947640954793, -0.0324623109241, 0.0299659889534, 0.092277502421, 0.154229382898, 0.215580185401, 0.276090807527, 0.335525421307, 0.393652392298, 0.450245182331, 0.505083232398, 0.557952822239, 0.60864790327, 0.656970901616, 0.702733488119, 0.745757312311, 0.785874697496, 0.822929294242, 0.856776689717, 0.88728497051, 0.914335236738, 0.937822065434, 0.957653921411, 0.973753514001, 0.986058098284, 0.99451971962, 0.999105400542, 0.999797269282, 0.996592629421, 0.989503970398, 0.978558918834, 0.963800130865, 0.945285125896, 0.923086062432, 0.897289456854, 0.867995846239, 0.835319396538, 0.799387457636, 0.760340067033, 0.718329404072, 0.673519196856, 0.626084084148, 0.576208934751, 0.52408812702, 0.46992479131, 0.413930018321, 0.356322036409, 0.297325361086, 0.237169920019, 0.17609015693, 0.114324117901, 0.0521125236353, -0.010302168701, -0.0726767104085, -0.134768009267, -0.196334076937, -0.257134972065, -0.316933735399, -0.375497313297, -0.432597466003, -0.488011657165, -0.541523921129, -0.592925704618, -0.642016679527, -0.688605523663, -0.732510666385, -0.773560996237, -0.811596527822, -0.846469025311, -0.878042580165, -0.906194140811, -0.930813992207, -0.951806183438, -0.969088901664, -0.982594790971, -0.992271214874, -0.998080461457, -0.999999890353, -0.998022020973, -0.992154561664, -0.982420379669, -0.968857412003, -0.951518517601, -0.930471271315, -0.905797700549, -0.87759396558, -0.845969984787, -0.811049006269, -0.772967127511, -0.73187276497, -0.68792607565, -0.641298332928, -0.592171259045, -0.540736316882, -0.487193963772, -0.43175287026, -0.374629106846, -0.316045301899, -0.256229774008, -0.19541564215, -0.133839917164, -0.071742578042, -0.00936563666373, 0.0530478053981, 0.115254504317, 0.177012022005, 0.23807967097, 0.298219452342, 0.357196983429, 0.414782411175, 0.470751307969};



float magnitudeSpectrum[256] = {9.45785522461, 8.28762177726, 5.54636495108, 7.52994910582, 18.7385848643, 6.02392518006, 5.79537508673, 2.47023979276, 9.62228507663, 19.4318333827, 6.04529835415, 3.88020982185, 2.3229130313, 6.53932646134, 2.47399957556, 3.89445492729, 1.90857008963, 2.63985936028, 2.19540393532, 2.04191897864, 1.04591104444, 3.95024411724, 1.98802730871, 0.294000836589, 0.801757257514, 0.582514277427, 2.24200596657, 1.22429749001, 0.978967236917, 0.513869291012, 2.10613274228, 0.526076753483, 0.0876521548048, 0.471194836094, 2.87910095928, 1.74253584791, 1.03287139651, 1.08791541086, 1.37469344747, 1.69881750557, 0.246124468335, 0.321454897243, 1.2317944288, 0.786751249749, 0.204404731234, 0.375745860243, 0.736210790626, 0.321932762352, 0.781011559902, 0.430341591504, 0.144722551287, 0.601260425031, 0.894287660519, 0.697301001903, 0.084314827537, 0.209436091386, 0.495396144619, 0.435476819629, 0.415009292324, 0.508861804399, 0.0929232896246, 0.408073375686, 0.429750934936, 0.500971541215, 0.151676426737, 0.18444624082, 0.52722544461, 0.417880956166, 0.637815279073, 0.419433035412, 0.271871446269, 0.616835052731, 0.324932052536, 0.287252626815, 0.260174087595, 0.224622570778, 0.248477436042, 0.188123310271, 0.142117536174, 0.208892512484, 0.26133477151, 0.111642618997, 0.369441684099, 0.122828578685, 0.256084400511, 0.348225168046, 0.920068305726, 0.178688753677, 0.292798675735, 0.09345038249, 0.6050588939, 0.298661307299, 0.265657139952, 0.324389105523, 0.287767076793, 0.672962295338, 0.473562866323, 0.365058182648, 0.377435109515, 0.552537050609, 0.311480995115, 0.210447944712, 0.195735430909, 0.376127495671, 0.137190670751, 0.271723961978, 0.330706778035, 0.29530765956, 0.104818148073, 0.176496828039, 0.178809261636, 0.160640995033, 0.159379955662, 0.0858051446487, 0.209935011562, 0.0938830916111, 0.174908907657, 0.140284234186, 0.297900149525, 0.15153171448, 0.339839653183, 0.661555552899, 0.366053561517, 0.791207021076, 0.303771136747, 0.605876395246, 0.157098725384, 0.355035584735, 0.131961864798, 0.263653966836, 0.380890938123, 0.497806329766, 0.45823969904, 0.464039510549, 0.190725425362, 0.288586606899, 0.103339792853, 0.194165034213, 0.074832313505, 0.0822788755509, 0.0294386398262, 0.225656689628, 0.123060832405, 0.149287155815, 0.116502788319, 0.141695853092, 0.115599995893, 0.117152588849, 0.156415082411, 0.116933322422, 0.136426169972, 0.166175023087, 0.278800840196, 0.186183325128, 0.102700407946, 0.291374817157, 0.14933170389, 0.129093808502, 0.136445894252, 0.11261058986, 0.132262234171, 0.110186901928, 0.16109126595, 0.146314170541, 0.245880803311, 0.179475351622, 0.322401379442, 0.269751536018, 0.372252947273, 0.275469541067, 0.581219917983, 0.161359064041, 0.374549581035, 0.423380559351, 0.0370719843667, 0.053273665892, 0.119389069656, 0.0892840860303, 0.020491605349, 0.0672975928622, 0.144250253749, 0.157752585511, 0.0778168100583, 0.0116788953115, 0.133442360737, 0.173175180607, 0.0330708078198, 0.187456623571, 0.136484880224, 0.142340950721, 0.142735822452, 0.109463830616, 0.155546950488, 0.134397279917, 0.145242921527, 0.140647063689, 0.065488461697, 0.120735761819, 0.156063271129, 0.0802574149996, 0.0774369661967, 0.10682849864, 0.135577103837, 0.105061526232, 0.126561632826, 0.111035818937, 0.0784463015416, 0.148110442231, 0.0893802495012, 0.1580961991, 0.0891006797679, 0.105412074325, 0.0993753122671, 0.110697943883, 0.102278160495, 0.0924815422631, 0.0846062159909, 0.0612685395086, 0.0653106917947, 0.0797524030654, 0.0545086425233, 0.130721938517, 0.147674699598, 0.205721485046, 0.167390105729, 0.106946002298, 0.152980886793, 0.141938115112, 0.11428073701, 0.10308070962, 0.124344235402, 0.122817389661, 0.078900341875, 0.140523198457, 0.0835096597094, 0.116091559176, 0.112477396628, 0.0796096523067, 0.129080532043, 0.111688283846, 0.133115627286, 0.11610780111, 0.0978551293338, 0.102282743929, 0.096924308493, 0.105786616835, 0.112553806002, 0.1156238858, 0.116423394553, 0.0871395671186, 0.10835649115, 0.103075523383, 0.111022208075, 0.0963715802761, 0.100055641998, 0.0908138822976};


float mfccTest1_result[13] = {73.65103872,35.45822745,5.82885881,0.23033413,-3.08939408, -0.87813575,  -6.20776523,  -1.74532503,0.72425734, 0.77592405, 0.17619458,  1.68907138,  1.97074582};


float fftTestIn[256] = { 0.52834005,  0.31279196,  0.94732986,  0.17100424,  0.38965468,
                         0.99907744,  0.13977969,  0.78260332,  0.5120757 ,  0.01031854,
                         0.54153062,  0.04847486,  0.24755871,  0.5610206 ,  0.18503912,
                         0.95461251,  0.10771222,  0.14235935,  0.84869375,  0.20847707,
                         0.97487571,  0.83551629,  0.95575955,  0.45460246,  0.56861381,
                         0.78819564,  0.60101869,  0.28661048,  0.39303333,  0.24168271,
                         0.18216275,  0.18044893,  0.90432498,  0.70645771,  0.63095375,
                         0.16493781,  0.13745874,  0.09361482,  0.36769649,  0.45762157,
                         0.90458696,  0.87075836,  0.95975382,  0.98608291,  0.12000475,
                         0.26548749,  0.1986734 ,  0.36752634,  0.66912236,  0.07894431,
                         0.00957718,  0.85247125,  0.80700631,  0.31313473,  0.91840324,
                         0.81417501,  0.03595648,  0.99230103,  0.70360895,  0.18501715,
                         0.53897057,  0.13461374,  0.33728673,  0.7916893 ,  0.50751962,
                         0.47815961,  0.98174532,  0.97070334,  0.17437332,  0.93462806,
                         0.03476602,  0.10721703,  0.31218742,  0.48420087,  0.2782694 ,
                         0.43641784,  0.00868399,  0.02348784,  0.95353424,  0.5968708 ,
                         0.59797581,  0.36851166,  0.88522612,  0.82537391,  0.42964711,
                         0.35943556,  0.48781475,  0.60309441,  0.94074815,  0.67298388,
                         0.6118911 ,  0.32840702,  0.80169693,  0.08116283,  0.952191  ,
                         0.5916859 ,  0.02243115,  0.88669829,  0.24773505,  0.36948656,
                         0.10889599,  0.77761367,  0.27147085,  0.43499082,  0.77636765,
                         0.46579944,  0.85430935,  0.41457601,  0.27082752,  0.54973844,
                         0.10472035,  0.39841948,  0.33503715,  0.64577586,  0.09381328,
                         0.75509055,  0.69179448,  0.18213553,  0.01336358,  0.1318987 ,
                         0.46994143,  0.8501252 ,  0.90089276,  0.16419846,  0.35043076,
                         0.56213097,  0.9541064 ,  0.74999752,  0.7066202 ,  0.60575576,
                         0.37960274,  0.57224016,  0.8472904 ,  0.78430749,  0.85790049,
                         0.03601504,  0.18943752,  0.07899453,  0.39942417,  0.5164256 ,
                         0.85596727,  0.36233199,  0.05911363,  0.34830207,  0.69640164,
                         0.75030657,  0.55255894,  0.50335743,  0.13941249,  0.07506053,
                         0.58775124,  0.66705985,  0.80388415,  0.5060009 ,  0.20990093,
                         0.86388416,  0.66408331,  0.99074173,  0.65262353,  0.27725482,
                         0.07972371,  0.53068607,  0.57421305,  0.73015015,  0.98976641,
                         0.40071058,  0.8085872 ,  0.12216473,  0.41599995,  0.73561325,
                         0.19858847,  0.08552754,  0.25178395,  0.67718127,  0.80055734,
                         0.67093277,  0.9101736 ,  0.45668975,  0.5904466 ,  0.84371983,
                         0.00331109,  0.70707794,  0.71222782,  0.59130464,  0.16208248,
                         0.17158441,  0.4310234 ,  0.65093265,  0.99952918,  0.8413812 ,
                         0.78997699,  0.86187005,  0.64209272,  0.55075006,  0.22150276,
                         0.6404383 ,  0.00278799,  0.0702754 ,  0.3610021 ,  0.25550797,
                         0.7445179 ,  0.87025348,  0.85955474,  0.55712374,  0.44955402,
                         0.15348976,  0.54179777,  0.93019741,  0.74070661,  0.50004275,
                         0.31080341,  0.57853441,  0.88564589,  0.76341747,  0.52170547,
                         0.16823532,  0.34674215,  0.39754405,  0.15416637,  0.59833572,
                         0.12223957,  0.11377274,  0.63784479,  0.64851109,  0.41824447,
                         0.24780466,  0.11597387,  0.14594527,  0.71802183,  0.97452451,
                         0.07449269,  0.13339997,  0.25892959,  0.07824378,  0.07195134,
                         0.06649456,  0.05635982,  0.63379061,  0.21151409,  0.28261039,
                         0.27344882,  0.51976379,  0.56609186,  0.4205897 ,  0.9144607 ,
                         0.76694702,  0.36326626,  0.52792292,  0.49874483,  0.18756497,
                         0.45081328,  0.99453402,  0.27989211,  0.76979844,  0.30758767,
                         0.9219236};

float fftTestMag[256] = { 125.97089164,    3.30166241,    5.26864495,    4.08995426,
                         3.99142391,    3.33765646,    4.77614131,    4.20013023,
                         7.93236255,    2.56718555,    2.75886031,    5.82346236,
                         6.4614667 ,    4.11830441,    4.12179776,    7.99100455,
                         4.31304661,    4.27843446,    0.22800705,    6.95901961,
                         3.62464666,   11.28417318,    0.73162724,    8.82593329,
                         3.04356678,    2.97398495,    5.45822869,    5.18487997,
                         2.2454668 ,    7.5293101 ,    3.16079889,    7.44876808,
                         1.6059957 ,    5.0546822 ,    3.89904383,    2.04252839,
                         1.49958313,    2.91007302,    8.29972873,    4.23865741,
                         1.93450457,   10.20567907,    9.06357618,    8.01435954,
                         3.3337148 ,    6.96571466,    6.20922118,    1.72379121,
                         7.25296962,    5.19733084,    4.62298333,    6.05965398,
                         0.8313258 ,    6.55790337,    1.51573976,    4.10701022,
                         2.89538324,    3.6531271 ,    2.59197724,    3.77096172,
                         4.05147675,    2.38989069,    4.62839076,    1.21882719,
                         0.83467037,    3.12620614,    3.60910282,    3.89984136,
                         3.60631502,    4.27283499,    2.77733189,    4.05754434,
                         4.92587515,    0.31426097,    3.03419675,    1.48099385,
                         2.28039997,    4.80625235,    4.79394516,    2.97583326,
                         2.90505379,    2.36817387,    9.2146307 ,    4.07519457,
                         9.18188923,    2.53585387,    1.94529475,    5.94157236,
                         5.61283234,    6.66920444,    4.33959655,    3.73626696,
                         2.63761667,    2.91241544,    5.65952066,    5.3002919 ,
                         1.75551911,    7.93967681,    5.4236355 ,    5.1110585 ,
                         5.05902039,    2.64169146,    3.55606471,    6.99152352,
                         4.58605375,    1.68197422,    5.67463783,    4.20553393,
                         1.90785671,    4.76385729,    8.40678554,    7.10557519,
                         2.29398087,    2.93005169,    2.98553694,    2.84006029,
                         2.01784927,    1.3909425 ,    2.28372583,    3.19263317,
                         1.0340331 ,    4.52005557,    3.57860792,    4.32387787,
                         4.49949954,    2.50468046,    2.50174788,    1.55868067,
                         1.50410699,    1.55868067,    2.50174788,    2.50468046,
                         4.49949954,    4.32387787,    3.57860792,    4.52005557,
                         1.0340331 ,    3.19263317,    2.28372583,    1.3909425 ,
                         2.01784927,    2.84006029,    2.98553694,    2.93005169,
                         2.29398087,    7.10557519,    8.40678554,    4.76385729,
                         1.90785671,    4.20553393,    5.67463783,    1.68197422,
                         4.58605375,    6.99152352,    3.55606471,    2.64169146,
                         5.05902039,    5.1110585 ,    5.4236355 ,    7.93967681,
                         1.75551911,    5.3002919 ,    5.65952066,    2.91241544,
                         2.63761667,    3.73626696,    4.33959655,    6.66920444,
                         5.61283234,    5.94157236,    1.94529475,    2.53585387,
                         9.18188923,    4.07519457,    9.2146307 ,    2.36817387,
                         2.90505379,    2.97583326,    4.79394516,    4.80625235,
                         2.28039997,    1.48099385,    3.03419675,    0.31426097,
                         4.92587515,    4.05754434,    2.77733189,    4.27283499,
                         3.60631502,    3.89984136,    3.60910282,    3.12620614,
                         0.83467037,    1.21882719,    4.62839076,    2.38989069,
                         4.05147675,    3.77096172,    2.59197724,    3.6531271 ,
                         2.89538324,    4.10701022,    1.51573976,    6.55790337,
                         0.8313258 ,    6.05965398,    4.62298333,    5.19733084,
                         7.25296962,    1.72379121,    6.20922118,    6.96571466,
                         3.3337148 ,    8.01435954,    9.06357618,   10.20567907,
                         1.93450457,    4.23865741,    8.29972873,    2.91007302,
                         1.49958313,    2.04252839,    3.89904383,    5.0546822 ,
                         1.6059957 ,    7.44876808,    3.16079889,    7.5293101 ,
                         2.2454668 ,    5.18487997,    5.45822869,    2.97398495,
                         3.04356678,    8.82593329,    0.73162724,   11.28417318,
                         3.62464666,    6.95901961,    0.22800705,    4.27843446,
                         4.31304661,    7.99100455,    4.12179776,    4.11830441,
                         6.4614667 ,    5.82346236,    2.75886031,    2.56718555,
                         7.93236255,    4.20013023,    4.77614131,    3.33765646,
                         3.99142391,    4.08995426,    5.26864495,    3.30166241};