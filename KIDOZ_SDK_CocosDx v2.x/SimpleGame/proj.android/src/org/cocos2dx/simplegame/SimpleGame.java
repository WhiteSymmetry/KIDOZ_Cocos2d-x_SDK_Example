/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
 ****************************************************************************/
package org.cocos2dx.simplegame;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.view.ViewGroup.LayoutParams;
import android.widget.Button;
import android.widget.RelativeLayout;
import android.widget.Toast;
import com.kidoz.sdk.api.FeedButton;
import com.kidoz.sdk.api.FlexiView;
import com.kidoz.sdk.api.KidozInterstitial;
import com.kidoz.sdk.api.KidozSDK;
import com.kidoz.sdk.api.PanelView;
import com.kidoz.sdk.api.interfaces.FlexiViewListener;
import com.kidoz.sdk.api.ui_views.flexi_view.FLEXI_POSITION;
import com.kidoz.sdk.api.ui_views.interstitial.BaseInterstitial;

public class SimpleGame extends Cocos2dxActivity {
	private FeedButton mFeedButton;
	private PanelView mPanelView;
	private FlexiView mFlexiView;
	private KidozInterstitial mInterstitial;

	private RelativeLayout mSdkContainer;

	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		// Initialize SDK instance
		KidozSDK.initialize(SimpleGame.this, "5",
				"i0tnrdwdtq0dm36cqcpg6uyuwupkj76s");

		// Create a container that will hold KIDOZ elements
		mSdkContainer = new RelativeLayout(getContext());

		// Add container to main application view
		addContentView(mSdkContainer, new LayoutParams(
				LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT));

		/** Initiate and add Feed Button view */
		addFeedButtonToView();

		/** Initiate and add Panel view */
		addPanelToView();
		
		/** Initiate and add Flexi view */
		addFlexiPointToView();

		/** Initiate and add Flexi view */
		initInterstitial();
	}

	/** Initiate and add Feed Button view */
	private void addFeedButtonToView() {
		// Create KIDOZ Feed Button instance
		mFeedButton = new FeedButton(this);

		// Add button to container and place it as desired
		RelativeLayout.LayoutParams params = new RelativeLayout.LayoutParams(
				LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT);
		params.addRule(RelativeLayout.ALIGN_PARENT_RIGHT);
		mSdkContainer.addView(mFeedButton, params);
	}

	/** Initiate and add Panel view */
	private void addPanelToView() {
		// Create KIDOZ Panel View instance
		mPanelView = new PanelView(this);

		// Add panel to container and place it as desired
		mSdkContainer.addView(mPanelView, new LayoutParams(
				LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT));
	}

	private void addFlexiPointToView() {
		mFlexiView = (new FlexiView(SimpleGame.this));
		mFlexiView.setAutoShow(true);
		mFlexiView.setFlexiViewInitialPosition(FLEXI_POSITION.MIDDLE_CENTER);
		mFlexiView.setOnFlexiViewEventListener(new FlexiViewListener() {
			@Override
			public void onViewReady() {
				super.onViewReady();
				Toast.makeText(SimpleGame.this, "Flexi Ready",
						Toast.LENGTH_SHORT).show();
			}

			@Override
			public void onViewHidden() {
				super.onViewHidden();
				Toast.makeText(SimpleGame.this, "Flexi Hidden",
						Toast.LENGTH_SHORT).show();
			}

			@Override
			public void onViewVisible() {
				super.onViewVisible();
				Toast.makeText(SimpleGame.this, "Flexi Visible",
						Toast.LENGTH_SHORT).show();
			}
		});

		// Add flexi view to container
		RelativeLayout.LayoutParams params = new RelativeLayout.LayoutParams(
				LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT);
		mSdkContainer.addView(mFlexiView, params);
	}

	/** Initiate interstitial view */
	private void initInterstitial() {
		mInterstitial = new KidozInterstitial(this);
		mInterstitial
				.setOnInterstitialEventListener(new BaseInterstitial.IOnInterstitialEventListener() {
					@Override
					public void onClosed() {
						Toast.makeText(SimpleGame.this, "Interstitial Closed",
								Toast.LENGTH_SHORT).show();
					}

					@Override
					public void onOpened() {
						Toast.makeText(SimpleGame.this, "Interstitial Opened",
								Toast.LENGTH_SHORT).show();
					}

					@Override
					public void onReady() {
						mInterstitial.show();
					}

					@Override
					public void onLoadFailed() {
						// TODO Auto-generated method stub
						
					}
				});

		Button launchInterstitialBtn = new Button(this);
		launchInterstitialBtn.setText("Open\nInterstitial");

		RelativeLayout.LayoutParams params = new RelativeLayout.LayoutParams(
				ViewGroup.LayoutParams.WRAP_CONTENT,
				ViewGroup.LayoutParams.WRAP_CONTENT);
		params.addRule(RelativeLayout.CENTER_VERTICAL);
		params.addRule(RelativeLayout.ALIGN_PARENT_RIGHT);

		launchInterstitialBtn.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) {

				if (mInterstitial.isLoaded() == false) {
					mInterstitial.loadAd();
					Toast.makeText(SimpleGame.this, "Loading...",
							Toast.LENGTH_SHORT).show();
				} else {
					mInterstitial.show();
				}
			}
		});

		mSdkContainer.addView(launchInterstitialBtn, params);
	}

	@Override
	protected void onStop() {
		super.onStop();

		//android.os.Process.killProcess(android.os.Process.myPid());
		//System.exit(1);
	}

	static {
		System.loadLibrary("game");
	}

	@Override
	public void onBackPressed() {
		System.exit(1);
		android.os.Process.killProcess(android.os.Process.myPid());		
	}
}
