package cn.lihui.game.consts;

import cn.lihui.game.operation.MoveDownOperation;
import cn.lihui.game.operation.MoveLeftOperation;
import cn.lihui.game.operation.MoveRightOperation;
import cn.lihui.game.operation.MoveUpOperation;
import cn.lihui.game.operation.i.IMoveOperation;

public enum MoveTypes {

	up(1, new MoveUpOperation()), down(2, new MoveDownOperation()), left(3,
			new MoveLeftOperation()), right(4, new MoveRightOperation());

	public int type;
	IMoveOperation mo;

	MoveTypes(Integer type, IMoveOperation mo) {
		this.type = type;
		this.mo = mo;
	}

	public static IMoveOperation getMoveOperationByType(int type) {
		for (MoveTypes mt : MoveTypes.values()) {
			if (mt.type == type) {
				return mt.mo;
			}
		}

		return null;
	}

	public static String getMoveNameByType(int type) {
		for (MoveTypes mt : MoveTypes.values()) {
			if (mt.type == type) {
				return mt.name();
			}
		}

		return "";
	}
}
