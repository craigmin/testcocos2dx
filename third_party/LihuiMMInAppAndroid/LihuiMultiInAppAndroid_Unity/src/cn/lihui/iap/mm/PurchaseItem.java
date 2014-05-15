package cn.lihui.iap.mm;


public enum PurchaseItem {
	coins0("coins0", "金币500","30000821045305","140318029249","F4EDD676FDA673C8E0430100007F5628", "2.00"),
	coins1("coins1", "金币1800","30000821045306","140318029250","F4EDD676FDA773C8E0430100007F5628", "6.00"),
	coins2("coins2", "金币3900","30000821045304","140318029251", "F4EDD676FDA873C8E0430100007F5628", "12.00"),
	coins3("coins3", "金币11300","30000821045308","", "购买获得11300金条", "30.00"),
	gold0("gold0", "金条11","30000821045301","140318029246", "F4EDD676FDA373C8E0430100007F5628", "2.00"),
	gold1("gold1", "金条39","30000821045302","140318029247", "F4EDD676FDA473C8E0430100007F5628", "6.00"),
	gold2("gold2", "金条86","30000821045303","140318029248", "F4EDD676FDA573C8E0430100007F5628", "12.00"),
	gold3("gold3", "金条248","30000821045307","", "购买获得248金条", "30.00"),
	//unlimitedLive("lives", "测试", "140120022758", "0.10");
	unlimitedLive("lives","7天无限生命","30000821045309", "", "解锁获得7天无限生命模式的使用权", "30.00");

//	gift("gift", "大礼包","30000826541107","007","F8A4106ABB890B6AE0430100007FA308", "5.00"),
//	bombs3("3bombs", "炸弹3个","30000826541101","001","F8A4106ABB830B6AE0430100007FA308", "2.00"),
//	bombs5("5bombs", "炸弹5个","30000826541102","002", "F8A4106ABB840B6AE0430100007FA308", "3.00"),
//	bombs10("10bombs", "炸弹10个","30000826541103","003", "F8A4106ABB850B6AE0430100007FA308", "5.00"),
//	Re1("1Re", "重新排列1个","30000826541104","004", "F8A4106ABB860B6AE0430100007FA308", "2.00"),
//	Res2("2Res", "重新排列2个","30000826541105","005", "F8A4106ABB870B6AE0430100007FA308", "3.00"),
//	Res5("5Res", "重新排列5个","30000826541106","006", "F8A4106ABB880B6AE0430100007FA308", "5.00");
	
	public String title;
	// 中国移动item id
	public String idContentMM;
	// 中国联通item id
	public String idContentWO;
	// 中国电信item id
	public String idContentTE;
	public String prize;
	public String type;

	PurchaseItem(String type, String title, String idContentMM, String idContentWO,String idContentTE, String prize) {
		this.type = type;
		this.title = title;
		this.idContentMM = idContentMM;
		this.prize = prize;
		this.idContentWO = idContentWO;
		this.idContentTE = idContentTE;
	} 
	
	public static PurchaseItem getPurchaseItemByType(String type){
		if (type != null && !"".equals(type)) {
			for (PurchaseItem item : PurchaseItem.values()) {
				if (type.contains(item.type)) {
					return item;
				}
			}
		}
		return null;
	}
}
